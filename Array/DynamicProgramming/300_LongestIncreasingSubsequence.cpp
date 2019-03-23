//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int lengthOfLIS(vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//
//    int n = nums.size();
//    vector<int> dp(n, 1);
//    int res = 1;
//
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            if (nums[j] < nums[i])
//                dp[i] = max(dp[i], dp[j] + 1);
//        }
//
//        res = max(res, dp[i]);
//    }
//
//    return res;
//}
//
//int lengthOfLIS2(vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//
//    vector<int> res;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        auto iter = lower_bound(res.begin(), res.end(), nums[i]);
//        if (iter == res.end())
//            res.emplace_back(nums[i]);
//        else
//            *iter = nums[i];
//    }
//
//    return res.size();
//}
//
//void testLengthOfLIS()
//{
//    vector<int> nums{ 10,9,2,5,3,7,101,18 };
//
//    cout << lengthOfLIS(nums) << endl;
//}
//
//int main()
//{
//    testLengthOfLIS();
//
//    getchar();
//    return 0;
//}