//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////Definition for an interval.
//struct Interval {
//    int start;
//    int end;
//    Interval() : start(0), end(0) {}
//    Interval(int s, int e) : start(s), end(e) {}
//    
//    void display()
//    {
//        std::cout << start << ", " << end << endl;
//    }
//};
//
//
//vector<Interval> merge(vector<Interval>& intervals)
//{
//    if (intervals.size() < 2)
//        return intervals;
//
//    auto myCmp = [](const Interval& a, const Interval& b) { return a.start < b.start; };
//    sort(intervals.begin(), intervals.end(), myCmp);
//
//    for (auto iter = intervals.begin(); iter != intervals.end() - 1;)
//    {
//        if (iter->end >= (iter + 1)->start)
//        {
//            (iter + 1)->start = iter->start;
//            (iter + 1)->end = max(iter->end, (iter + 1)->end);
//            iter = intervals.erase(iter, iter + 1);
//        }
//        else
//            ++iter;
//    }
//
//    return intervals;
//}
//
//vector<Interval> merge2(vector<Interval>& intervals)
//{
//    if (intervals.size() < 2)
//        return intervals;
//
//    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; });
//
//    vector<Interval> res;
//    res.emplace_back(intervals[0]);
//    for (int i = 1; i < intervals.size(); ++i)
//    {
//        if (intervals[i].start > res.back().end)
//            res.emplace_back(intervals[i]);
//        else
//            res.back().end = max(res.back().end, intervals[i].end);
//    }
//
//    return res;
//}
//
//void testMerge()
//{
//    vector<Interval> intervals = { Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };
//    auto res = merge2(intervals);
//
//    for (auto& i : res)
//        i.display();
//}
//
//int main()
//{
//    testMerge();
//    getchar();
//}