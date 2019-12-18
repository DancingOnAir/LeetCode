#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;

//class DiningPhilosophers {
//public:
//    DiningPhilosophers(): mtxs(5)
//    {
//
//    }
//
//    void wantsToEat(int philosopher,
//        function<void()> pickLeftFork,
//        function<void()> pickRightFork,
//        function<void()> eat,
//        function<void()> putLeftFork,
//        function<void()> putRightFork)
//    {
//        int left = philosopher;
//        int right = (philosopher + 4) % 5;
//        bool odd = philosopher % 1;
//        int first = odd ? right : left;
//        int second = left + right - first;
//
//        unique_lock<mutex> lck1(mtxs[first]);
//        unique_lock<mutex> lck2(mtxs[second]);
//
//        pickLeftFork();
//        pickRightFork();
//        eat();
//        putLeftFork();
//        putRightFork();
//    }
//
//    thread threadWantsToEat(int philosopher,
//        function<void()> pickLeftFork,
//        function<void()> pickRightFork,
//        function<void()> eat,
//        function<void()> putLeftFork,
//        function<void()> putRightFork)
//    {
//        return thread([=] { return wantsToEat(philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork); });
//    }
//
//private:
//
//    vector<mutex> mtxs;
//};

class DiningPhilosophers {
public:
    DiningPhilosophers() : forks(5, false)
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

        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&] { return !forks[left] && !forks[right]; });

        forks[left] = forks[right] = true;
        lck.unlock();

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        lck.lock();
        forks[left] = forks[right] = false;
        cv.notify_all();
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
    mutex mtx;
    condition_variable cv;
    vector<bool> forks;
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


//class DiningPhilosophers {
//
//    condition_variable cv;
//    mutex m;
//
//    array<bool, 5> taken;
//
//public:
//    DiningPhilosophers() {
//        taken.fill(false);
//    }
//
//    void wantsToEat(int pid,
//        function<void()> pickLeftFork,
//        function<void()> pickRightFork,
//        function<void()> eat,
//        function<void()> putLeftFork,
//        function<void()> putRightFork) {
//        int r = pid - 1;
//        if (r == -1) {
//            r = 4;
//        }
//        int l = pid;
//
//        unique_lock<mutex> lk(m);
//        cv.wait(lk, [&]() {
//            return !taken[l] && !taken[r];
//        });
//
//        taken[l] = true;
//        taken[r] = true;
//
//        lk.unlock();
//
//        pickLeftFork();
//        pickRightFork();
//        eat();
//        putRightFork();
//        putLeftFork();
//
//        lk.lock();
//        taken[l] = taken[r] = false;
//
//        lk.unlock();
//        cv.notify_all();
//    }
//};