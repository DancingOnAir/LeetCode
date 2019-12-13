#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <future>
#include <atomic>
using namespace std;

class H2O {
public:
    H2O() {
        count = 0;
        //lck = ATOMIC_FLAG_INIT;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        


        while (count % 3 == 2)
            this_thread::yield();

        ++count;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {

        while (count % 3 != 2)
            this_thread::yield();

        count = 0;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }

    thread threadHydrogen(function<void()> releaseHydrogen)
    {
        return thread([=] { return hydrogen(releaseHydrogen); });
    }

    thread threadOxygen(function<void()> releaseOxygen)
    {
        return thread([=] {return oxygen(releaseOxygen); });
    }

private:
    promise<function<void()>> promOxygen;
    atomic<int> count;
    atomic_flag lck;
};

void printHydrogen()
{
    cout << "H" << endl;
}

void printOxygen()
{
    cout << "O" << endl;
}

void test()
{
    H2O* p = new H2O();

    string input = "OOHHHH";
    vector<thread> workers(input.size());
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == 'H')
            workers[i] = p->threadHydrogen(printHydrogen);

        if (input[i] == 'O')
            workers[i] = p->threadOxygen(printOxygen);
    }

    for (auto& t : workers)
        t.join();
}

int main()
{
    test();

    getchar();
    return 0;
}