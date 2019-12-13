#include <iostream>
#include <thread>
#include <string>
#include <vector>
using namespace std;

class H2O {
public:
    H2O() {

    }

    void hydrogen(function<void()> releaseHydrogen) {

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {

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