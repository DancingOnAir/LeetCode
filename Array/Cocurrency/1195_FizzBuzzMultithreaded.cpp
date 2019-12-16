#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <atomic>
using namespace std;

//class FizzBuzz {
//private:
//    int n;
//    promise<function<void()>> promFizz, promBuzz, promFizzBuzz;
//    promise<function<void(int)>> promNumber;
//
//public:
//    FizzBuzz(int n) {
//        this->n = n;
//    }
//
//    // printFizz() outputs "fizz".
//    void fizz(function<void()> printFizz) {
//        promFizz.set_value(printFizz);
//    }
//
//    // printBuzz() outputs "buzz".
//    void buzz(function<void()> printBuzz) {
//        promBuzz.set_value(printBuzz);
//    }
//
//    // printFizzBuzz() outputs "fizzbuzz".
//    void fizzbuzz(function<void()> printFizzBuzz) {
//        promFizzBuzz.set_value(printFizzBuzz);
//    }
//
//    // printNumber(x) outputs "x", where x is an integer.
//    void number(function<void(int)> printNumber) {
//        auto f = promFizz.get_future().get();
//        auto b = promBuzz.get_future().get();
//        auto fb = promFizzBuzz.get_future().get();
//
//        for (int i = 1; i <= n; ++i)
//        {
//            if (i % 5 == 0 && i % 3 == 0)
//                fb();
//            else if (i % 3 == 0)
//                f();
//            else if (i % 5 == 0)
//                b();
//            else
//                printNumber(i);
//        }
//    }
//
//    thread threadPrintFizz(function<void()> printFizz)
//    {
//        return thread([=] { return fizz(printFizz); });
//    }
//
//    thread threadPrintBuzz(function<void()> printBuzz)
//    {
//        return thread([=] { return buzz(printBuzz); });
//    }
//
//    thread threadPrintFizzBuzz(function<void()> printFizzBuzz)
//    {
//        return thread([=] {return fizzbuzz(printFizzBuzz); });
//    }
//
//    thread threadPrintNumber(function<void(int)> printNumber)
//    {
//        return thread([=] {return number(printNumber); });
//    }
//};

//class FizzBuzz3 {
//private:
//    int n;
//    int count;
//    mutex mtx;
//    condition_variable cv;
//
//public:
//    FizzBuzz3(int n) {
//        this->n = n;
//        this->count = 1;
//    }
//
//    // printFizz() outputs "fizz".
//    void fizz(function<void()> printFizz) {
//        while (true)
//        {
//            unique_lock<mutex> lck(mtx);
//            while (count <= n && (count % 3 != 0 || count % 5 == 0))
//                cv.wait(lck);
//
//            if (count > n)
//                return;
//
//            printFizz();
//            ++count;
//
//            cv.notify_all();
//        }
//    }
//
//    // printBuzz() outputs "buzz".
//    void buzz(function<void()> printBuzz) {
//        while (true)
//        {
//            unique_lock<mutex> lck(mtx);
//
//            while (count <= n && (count % 5 != 0 || count % 3 == 0))
//                cv.wait(lck);
//
//            if (count > n)
//                return;
//
//            printBuzz();
//            ++count;
//
//            cv.notify_all();
//        }
//    }
//
//    // printFizzBuzz() outputs "fizzbuzz".
//    void fizzbuzz(function<void()> printFizzBuzz) {
//        while (true)
//        {
//            unique_lock<mutex> lck(mtx);
//            while (count <= n && (count % 3 != 0 || count % 5 != 0))
//                cv.wait(lck);
//
//            if (count > n)
//                return;
//
//            printFizzBuzz();
//            ++count;
//
//            cv.notify_all();
//        }
//    }
//
//    // printNumber(x) outputs "x", where x is an integer.
//    void number(function<void(int)> printNumber) {
//
//        while (true)
//        {
//            unique_lock<mutex> lck(mtx);
//            while (count <= n && (count % 3 == 0 || count % 5 == 0))
//                cv.wait(lck);
//
//            if (count > n)
//                return;
//                
//            printNumber(count++);
//            cv.notify_all();
//        }
//
//    }
//
//    thread threadPrintFizz(function<void()> printFizz)
//    {
//        return thread([=] { return fizz(printFizz); });
//    }
//
//    thread threadPrintBuzz(function<void()> printBuzz)
//    {
//        return thread([=] { return buzz(printBuzz); });
//    }
//
//    thread threadPrintFizzBuzz(function<void()> printFizzBuzz)
//    {
//        return thread([=] {return fizzbuzz(printFizzBuzz); });
//    }
//
//    thread threadPrintNumber(function<void(int)> printNumber)
//    {
//        return thread([=] {return number(printNumber); });
//    }
//};

class FizzBuzz {
private:
    int n;
    atomic<int> count;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        auto outputx = [&](auto i) { return printFizz(); };
        output_if(outputx, [](auto i) { return i % 3 == 0 && i % 5 != 0; });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        auto outputx = [&](auto i) { return printBuzz(); };
        output_if(outputx, [](auto i) { return i % 3 != 0 && i % 5 == 0; });
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        auto outputx = [&](auto i) { return printFizzBuzz(); };
        output_if(outputx, [](auto i) { return i % 3 == 0 && i % 5 == 0; });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        auto outputx = [&](auto i) { return printNumber(i); };
        output_if(outputx, [](auto i) { return i % 3 != 0 && i % 5 != 0; });
    }

    template<typename T, typename U>
    inline void output_if(T printFunc, U condition)
    {
        while (count.load() <= n)
        {
            auto i = count.load();
            if (condition(i))
            {
                printFunc(i);
                count.store(i + 1);
            }
            else
                this_thread::yield();
        }
    }

    thread threadPrintFizz(function<void()> printFizz)
    {
        return thread([=] { return fizz(printFizz); });
    }

    thread threadPrintBuzz(function<void()> printBuzz)
    {
        return thread([=] { return buzz(printBuzz); });
    }

    thread threadPrintFizzBuzz(function<void()> printFizzBuzz)
    {
        return thread([=] {return fizzbuzz(printFizzBuzz); });
    }

    thread threadPrintNumber(function<void(int)> printNumber)
    {
        return thread([=] {return number(printNumber); });
    }
};

void printFizz()
{
    cout << "fizz" << endl;
}

void printBuzz()
{
    cout << "buzz" << endl;
}

void printFizzBuzz()
{
    cout << "fizzbuzz" << endl;
}

void printNumber(int x)
{
    cout << x << endl;
}

void testThread()
{
    int n = 16;
    vector<thread> ths(4);

    FizzBuzz* p = new FizzBuzz(n);
    ths[0] = p->threadPrintFizz(printFizz);
    ths[1] = p->threadPrintBuzz(printBuzz);
    ths[2] = p->threadPrintFizzBuzz(printFizzBuzz);
    ths[3] = p->threadPrintNumber(printNumber);


    for (auto& t : ths)
        t.join();
}

int main()
{
    testThread();

    getchar();
    return 0;
}