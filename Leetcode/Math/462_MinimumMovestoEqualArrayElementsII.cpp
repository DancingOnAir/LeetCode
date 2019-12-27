//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//
//using namespace std;
//
//int minMoves2(vector<int>& nums)
//{
//    int n = nums.size();
//    if (n < 2)
//        return 0;
//
//    auto iter = nums.begin() + nums.size() / 2;
//    nth_element(nums.begin(), iter, nums.end());
//    int mid = *iter;
//    int res = 0;
//    for (int x : nums)
//        res += abs(x - mid);
//
//    return res;
//}
//
//void testMinMoves2()
//{
//    vector<int> nums1 = { 1, 2, 3 };
//    cout << minMoves2(nums1) << endl;
//
//    vector<int> nums2 = { 1, 2, 6, 7 };
//    cout << minMoves2(nums2) << endl;
//}
//
//int main()
//{
//    testMinMoves2();
//
//    getchar();
//    return 0;
//}
