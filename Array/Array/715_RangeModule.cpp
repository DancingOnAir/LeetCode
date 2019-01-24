//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//class RangeModule {
//public:
//    RangeModule()
//    {
//
//    }
//
//    void addRange(int left, int right)
//    {
//        auto l = intervals.upper_bound(left);
//        auto r = intervals.upper_bound(right);
//        
//        if (l != intervals.begin())
//        {
//            --l;
//            if (l->second < left)
//                ++l;
//        }
//        
//        if (l != r)
//        {
//            left = min(left, l->first);
//            right = max(right, (--r)->second);
//
//            intervals.erase(l, ++r);
//        }
//
//        intervals[left] = right;
//    }
//
//    bool queryRange(int left, int right)
//    {
//        auto iter = intervals.upper_bound(left);
//        if (iter == intervals.begin() || (--iter)->second < right)
//            return false;
//
//        return true;
//    }
//
//    void removeRange(int left, int right)
//    {
//        auto l = intervals.upper_bound(left);
//        auto r = intervals.upper_bound(right);
//
//        if (l != intervals.begin())
//        {
//            --l;
//            if (l->second < left)
//                ++l;
//        }
//
//        if (l == r)
//            return;
//
//        int l1 = min(left, l->first);
//        int r1 = max(right, (--r)->second);
//        intervals.erase(l, ++r);
//
//        if (l1 < left)
//            intervals[l1] = left;
//
//        if (right < r1)
//            intervals[right] = r1;
//    }
//
//private:
//    map<int, int> intervals;
//};
//
//void testRangeModule()
//{
//    RangeModule obj = RangeModule();
//    int left = 10, right = 20;
//
//    obj.addRange(left, right);
//    obj.removeRange(14, 16);
//
//    bool q1 = obj.queryRange(10, 14);
//    bool q2 = obj.queryRange(13, 15);
//    bool q3 = obj.queryRange(16, 17);
//    
//    cout << (q1 ? "true" : "false") << endl;
//    cout << (q2 ? "true" : "false") << endl;
//    cout << (q3 ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testRangeModule();
//
//    getchar();
//    return 0;
//}