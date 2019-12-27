//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Interval
//{
//    int start;
//    int end;
//    Interval() : start(0), end(0) {}
//    Interval(int s, int e) : start(s), end(e) {}
//};
//
//vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
//{
//    auto my_cmp = [](const Interval &a, const Interval &b) { return a.end < b.start; };
//    auto iter1 = std::lower_bound(intervals.begin(), intervals.end(), newInterval, my_cmp);
//    auto iter2 = std::upper_bound(intervals.begin(), intervals.end(), newInterval, my_cmp);
//
//    if (iter1 == iter2)
//    {
//        intervals.insert(iter1, newInterval);
//    }
//    else
//    {
//        iter2--;
//        iter2->start = min(newInterval.start, iter1->start);
//        iter2->end = max(newInterval.end, iter2->end);
//        intervals.erase(iter1, iter2);
//    }
//
//    return intervals;
//
//    //auto compare = [](const Interval &intv1, const Interval &intv2) { return intv1.end < intv2.start; };
//    //auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
//    //auto itr1 = range.first, itr2 = range.second;
//
//    //if (itr1 == itr2)
//    //{
//    //    intervals.insert(itr1, newInterval);
//    //}
//    //else
//    //{
//    //    itr2--;
//    //    itr2->start = min(newInterval.start, itr1->start);
//    //    itr2->end = max(newInterval.end, itr2->end);
//    //    intervals.erase(itr1, itr2);
//    //}
//
//    return intervals;
//}
//
//int main()
//{
//    vector<Interval> intervals = { Interval(1, 3), Interval(6, 9) };
//    Interval newInterval = Interval(2, 5);
//
//    vector<Interval> result;
//    result = insert(intervals, newInterval);
//
//    for (auto v : result)
//    {
//        std::cout << v.start << ", " << v.end << std::endl;
//    }
//
//    getchar();
//    return 0;
//}