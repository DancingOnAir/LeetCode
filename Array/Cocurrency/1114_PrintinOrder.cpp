#include <functional>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <unordered_map>
using namespace std;

class Foo {
public:
    Foo(): count(1)
    {

    }

    void first(function<void()> printFirst)
    {
        unique_lock<mutex> lck(mtx);

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        count = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> lck(mtx);
        while (count != 2)
            cv.wait(lck);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) 
    {
        unique_lock<mutex> lck(mtx);
        while (count != 3)
            cv.wait(lck);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex mtx;
    condition_variable cv;
    int count;
};

class Foo2 {
public:
    Foo2() : 
    {
        mtx1.lock();
        mtx2.lock();
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx1.unlock();
    }

    void second(function<void()> printSecond)
    {
        mtx1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        mtx1.unlock();
        mtx2.unlock();
    }

    void third(function<void()> printThird)
    {
        mtx2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        mtx2.unlock();
    }

private:
    mutex mtx1;
    mutex mtx2;
};

void printFirst()
{
    cout << "fisrt" << endl;
}

void printSecond()
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "second" << endl;
    }
}

void printThird()
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "third" << endl;
    }
}

void test()
{
    vector<int> nums = { 1, 3, 2 };
    Foo foo;

    for (auto num : nums)
    {
        if (1 == num)
        {
            auto th1 = thread(foo.first, printFirst);
        }

        if (2 == num)
        {
            th2 = thread(printSecond);
        }

        if (3 == num)
        {
            th3 = thread(printThird);
        }
    }

    th1.join();
    th2.join();
    th3.join();
    cout << "main" << endl;
}

int main()
{
    test();

    getchar();
    return 0;
}