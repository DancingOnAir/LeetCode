#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    bool isZero;
    bool isEven;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        this->isZero = true;
        this->isEven = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        for (int i = 0; i < n; ++i)
        {
            //cv.wait(lck, [&] { return isZero; });
            while (!isZero)
                cv.wait(lck);

            printNumber(0);

            isZero = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        for (int i = 2; 2 <= n; i += 2)
        {
            //cv.wait(lck, [&] { return (!isZero && isEven); });
            while (isZero || !isEven)
                cv.wait(lck);
            printNumber(i);

            isEven = false;
            isZero = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        for (int i = 1; i <=n; i += 2)
        {
            //cv.wait(lck, [&] { return (!isZero && !isEven); });
            while (isZero || isEven)
                cv.wait(lck);

            printNumber(i);
            isZero = true;
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

void printNumber(int num)
{
    cout << num << endl;
}

void testZeroEvenOdd()
{
    function<void(int)> f = printNumber;
    
    ZeroEvenOdd* p = new ZeroEvenOdd(2);
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
