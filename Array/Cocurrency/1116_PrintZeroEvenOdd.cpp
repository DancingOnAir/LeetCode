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
    int count;
    int flag;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        count = 1;
        flag = -1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        while (count <= n)
        {
            while (-1 != flag)
                cv.wait(lck);

            printNumber(0);
            flag = count & 1;
        }
    }

    void even(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        while (count <= n)
        {
            while (1 != flag)
                cv.wait(lck);

            printNumber(count++);
            flag = -1;
        }
    }

    void odd(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(mtx);

        while (count <= n)
        {
            while (0 != flag)
                cv.wait(lck);

            printNumber(count++);
            flag = -1;
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
    
    ZeroEvenOdd* p = new ZeroEvenOdd(4);
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
