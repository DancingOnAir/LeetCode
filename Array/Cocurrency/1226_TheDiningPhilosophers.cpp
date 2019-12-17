#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;

class DiningPhilosophers {
public:
    DiningPhilosophers(): mtxs(5)
    {

    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork)
    {
        int left = philosopher;
        int right = (philosopher + 4) % 5;
        bool odd = philosopher % 1;
        int first = odd ? right : left;
        int second = left + right - first;

        unique_lock<mutex> lck1(mtxs[first]);
        unique_lock<mutex> lck2(mtxs[second]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

    thread threadWantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork)
    {
        return thread([=] { return wantsToEat(philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork); });
    }

private:

    vector<mutex> mtxs;
};

void pickLeftFork()
{
    cout << "pick left fork." << endl;
}

void pickRightFork()
{
    cout << "pick right fork." << endl;
}

void eat()
{
    cout << "eat." << endl;
}

void putLeftFork()
{
    cout << "put left fork." << endl;
}

void putRightFork()
{
    cout << "put right fork." << endl;
}

void testDiningPhilosophers()
{
    vector<thread> ths(5);
    DiningPhilosophers* p = new DiningPhilosophers();
    for (int i = 0; i < 5; ++i)
    {
        ths[i] = p->threadWantsToEat(i, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork);
    }

    for (auto& t : ths)
        t.join();
}

int main()
{
    testDiningPhilosophers();

    getchar();
    return 0;
}