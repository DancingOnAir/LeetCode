#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <future>
#include <atomic>
#include <queue>
using namespace std;

//class H2O {
//public:
//    H2O() {
//        count = 0;
//        //lck = ATOMIC_FLAG_INIT;
//    }
//
//    void hydrogen(function<void()> releaseHydrogen) {
//        
//
//
//        while (count % 3 == 2)
//            this_thread::yield();
//
//        ++count;
//        // releaseHydrogen() outputs "H". Do not change or remove this line.
//        releaseHydrogen();
//    }
//
//    void oxygen(function<void()> releaseOxygen) {
//
//        while (count % 3 != 2)
//            this_thread::yield();
//
//        count = 0;
//        // releaseOxygen() outputs "O". Do not change or remove this line.
//        releaseOxygen();
//    }
//
//    thread threadHydrogen(function<void()> releaseHydrogen)
//    {
//        return thread([=] { return hydrogen(releaseHydrogen); });
//    }
//
//    thread threadOxygen(function<void()> releaseOxygen)
//    {
//        return thread([=] {return oxygen(releaseOxygen); });
//    }
//
//private:
//    promise<function<void()>> promOxygen;
//    atomic<int> count;
//    atomic_flag lck;
//};

//class H2O {
//public:
//    H2O() {
//
//    }
//
//    future<void> handle_atom(queue<promise<void>>& q)
//    {
//        unique_lock<mutex> lck(mtx);
//        promise<void> p;
//        future<void> f = p.get_future();
//        q.emplace(move(p));
//
//        if (h.size() > 1 && o.size() > 0)
//        {
//            o.front().set_value();
//            o.pop();
//            h.front().set_value();
//            h.pop();
//            h.front().set_value();
//            h.pop();
//        }
//
//        return f;
//    }
//
//    void hydrogen(function<void()> releaseHydrogen) {
//        handle_atom(h).get();
//        // releaseHydrogen() outputs "H". Do not change or remove this line.
//        releaseHydrogen();
//    }
//
//    void oxygen(function<void()> releaseOxygen) {
//        handle_atom(o).get();
//        // releaseOxygen() outputs "O". Do not change or remove this line.
//        releaseOxygen();
//    }
//
//    thread threadHydrogen(function<void()> releaseHydrogen)
//    {
//        return thread([=] { return hydrogen(releaseHydrogen); });
//    }
//
//    thread threadOxygen(function<void()> releaseOxygen)
//    {
//        return thread([=] {return oxygen(releaseOxygen); });
//    }
//
//private:
//    queue<promise<void>> h;
//    queue<promise<void>> o;
//    mutex mtx;
//};

class H2O {
public:
    H2O()
    {
        count = 0;
        mtx1.lock();
        mtx2.lock();

        mtx1.unlock();
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        mtx1.lock();
        ++count;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        if (count & 1)
            mtx1.unlock();
        else
            mtx2.unlock();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        mtx2.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        mtx1.unlock();
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
    int count;
    mutex mtx1;
    mutex mtx2;
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

    string input = "HHHHHHHHHHOHHOHHHHOOHHHOOOOHHOOHOHHHHHOOHOHHHOOOOOOHHHHHHHHH";
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