//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//int thirdMax(vector<int>& nums)
//{
//    set<int> top3;
//    for (auto x : nums)
//    {
//        top3.insert(x);
//
//        if (top3.size() > 3)
//            top3.erase(top3.begin());
//    }
//
//    return (top3.size() == 3 ? *top3.begin() : *top3.rbegin());
//}
//
//void testThridMax()
//{
//    vector<int> nums = { 2, 3, 2, 1 };
//
//    cout << thirdMax(nums) << endl;
//}
//
//int main()
//{
//    testThridMax();
//
//    getchar();
//    return 0;
//}