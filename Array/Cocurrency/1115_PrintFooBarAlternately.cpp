#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    int count;

public:
    FooBar(int n)
    {
        this->n = n;
        this->count = 1;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            while (1 != count)
                cv.wait(lck);

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            count = 2;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            while (2 != count)
                cv.wait(lck);

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            count = 1;
            cv.notify_all();
        }
    }

    thread threadFoo(function<void()> printFoo)
    {
        return thread([=] { return foo(printFoo); });
    }

    thread threadBar(function<void()> printBar)
    {
        return thread([=] { return bar(printBar); });
    }
};

void printFoo()
{
    cout << "Foo" << endl;
}

void printBar()
{
    cout << "Bar" << endl;
}

void test()
{
    FooBar* p = new FooBar(5);
    
    thread th1 = p->threadFoo(printFoo);
    thread th2 = p->threadBar(printBar);
    th1.join();
    th2.join();
}

int main()
{
    test();

    getchar();
    return 0;
}