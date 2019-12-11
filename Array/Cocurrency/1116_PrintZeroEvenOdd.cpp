#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd2 {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    int isZero;
    bool isEven;

public:
    ZeroEvenOdd2(int n)
    {
        this->n = n;
        this->isZero = 1;
        this->isEven = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        for (int i = 0; i < n; ++i)
        {
            //cv.wait(lck, [&] { return isZero; });
            while (isZero != 1)
                cv.wait(lck);

            printNumber(0);

            isZero = 0;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        for (int i = 2; 2 <= n; i += 2)
        {
            //cv.wait(lck, [&] { return (!isZero && isEven); });
            while (isZero == 1 || !isEven)
                cv.wait(lck);
            printNumber(i);

            isEven = false;
            isZero = 1;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        for (int i = 1; i <=n; i += 2)
        {
            //cv.wait(lck, [&] { return (!isZero && !isEven); });
            while (isZero == 1 || isEven)
                cv.wait(lck);

            printNumber(i);
            isZero = 1;
            isEven = true;
            cv.notify_all();
        }
    }

    thread threadZero(function<void(int)> printNumber)
    {
        return thread([=] { return zero(printNumber); });
    }

    thread threadEven(function<void(int)> printNumber)
    {
        return thread([=] { return even(printNumber); });
    }

    thread threadOdd(function<void(int)> printNumber)
    {
        return thread([=] {return odd(printNumber); });
    }
};

#include <future>

class ZeroEvenOdd {
private:
    int n;
    promise<function<void(int)>> promOdd;
    promise<function<void(int)>> promEven;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        auto eve = promEven.get_future().get();
        auto odd = promOdd.get_future().get();

        for (int i = 1; i <= n; ++i)
        {
            printNumber(0);

            if (i & 1)
                odd(i);
            else
                eve(i);
        }
    }

    void even(function<void(int)> printNumber)
    {
        promEven.set_value(printNumber);
    }

    void odd(function<void(int)> printNumber)
    {
        promOdd.set_value(printNumber);
    }

    thread threadZero(function<void(int)> printNumber)
    {
        return thread([=] { return zero(printNumber); });
    }

    thread threadEven(function<void(int)> printNumber)
    {
        return thread([=] { return even(printNumber); });
    }

    thread threadOdd(function<void(int)> printNumber)
    {
        return thread([=] {return odd(printNumber); });
    }
};

void printNumber(int num)
{
    cout << num << endl;
}

void testZeroEvenOdd()
{
    function<void(int)> f = printNumber;
    
    ZeroEvenOdd* p = new ZeroEvenOdd(6);
    thread A, B, C;
    A = p->threadZero(f);
    B = p->threadEven(f);
    C = p->threadOdd(f);

    A.join();
    B.join();
    C.join();
}

int main()
{
    testZeroEvenOdd();

    getchar();
    return 0;
}
