#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class MyCalendarTwo
{
public:
    MyCalendarTwo()
    {

    }

    bool validate(int start, int end)
    {
        auto p = make_pair(start, end);
        bool overlap = false;
        auto iter = overlaps.insert(p);
        if (iter != overlaps.begin())
        {
            auto pp = prev(iter);
            if (pp->second > start)
                overlap = true;
        }

        if (iter != prev(overlaps.end()))
        {
            auto pp = next(iter);
            if (pp->first < end)
                overlap = true;
        }

        overlaps.erase(iter);
        return overlap;
    }

    bool book(int start, int end)
    {
        if (validate(start, end))
            return false;

        auto p = make_pair(start, end);
        auto iter = intervals.insert(make_pair(p, end));
        if (iter != intervals.begin())
        {
            auto pp = prev(iter);
            if (pp->second > start)
            {
                auto newOverlap = make_pair(start, min(pp->second, end));
                overlaps.insert(newOverlap);
            }

            iter->second = max(pp->second, end);
        }
        
        auto nxt = next(iter);
        while (nxt != intervals.end() && nxt->first.first < end)
        {
            auto newOverlap = make_pair(nxt->first.first, min(nxt->second, end));
            overlaps.insert(newOverlap);
            nxt->second = max(nxt->second, end);
            nxt = next(nxt);
        }

        return true;
    }

private:
    multimap<pair<int, int>, int> intervals;
    multiset<pair<int, int>> overlaps;
};

void testMyCalendarTwo()
{
    MyCalendarTwo myCalendarTwo;
    bool res = myCalendarTwo.book(10, 20);
    cout << (res ? "true" : "false") << endl;

    res = myCalendarTwo.book(50, 60);
    cout << (res ? "true" : "false") << endl;

    res = myCalendarTwo.book(10, 40);
    cout << (res ? "true" : "false") << endl;

    res = myCalendarTwo.book(5, 15);
    cout << (res ? "true" : "false") << endl;

    res = myCalendarTwo.book(5, 10);
    cout << (res ? "true" : "false") << endl;

    res = myCalendarTwo.book(25, 55);
    cout << (res ? "true" : "false") << endl;
}

int main()
{
    testMyCalendarTwo();
    getchar();
    return 0;
}