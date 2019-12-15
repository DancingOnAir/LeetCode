#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {

    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {

    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {

    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {

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