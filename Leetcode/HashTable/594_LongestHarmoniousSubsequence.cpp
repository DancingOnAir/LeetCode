//#include <iostream>
//#include <vector>
//#include <map>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//int findLHS2(vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//
//    unordered_map<int, int> m;
//    int res = 0;
//    for (int i : nums)
//    {
//        ++m[i];
//        if (m.count(i + 1))
//            res = max(res, m[i] + m[i + 1]);
//
//        if (m.count(i - 1))
//            res = max(res, m[i] + m[i - 1]);
//    }
//
//    return res;
//}
//
//int findLHS(vector<int>& nums)
//{
//    sort(nums.begin(), nums.end());
//    int res = 0;
//
//    for (int i = 1, start = 0, new_start = 0; i < nums.size(); ++i)
//    {
//        if (nums[i] - nums[start] > 1)
//            start = new_start;
//        if (nums[i] != nums[i - 1])
//            new_start = i;
//
//        if (nums[i] - nums[start] == 1)
//            res = max(res, i - start + 1);
//    }
//
//    return res;
//}
//
//void testFindLHS()
//{
//    vector<int> nums = { 1,3,2,2,5,2,3,7 };
//    cout << findLHS(nums) << endl;
//}
//
//int main()
//{
//    testFindLHS();
//
//    getchar();
//    return 0;
//}