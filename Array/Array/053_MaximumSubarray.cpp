//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxSubArray(vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//
//    vector<int> dp(nums.size());
//    dp[0] = nums[0];
//    int res = nums[0];
//
//    for (size_t i = 1; i < nums.size(); ++i)
//    {
//        dp[i] = nums[i] + (dp[i - 1] > 0? dp[i - 1]:0);
//        res = max(res, dp[i]);
//    }
//
//    return res;
//}
//
//int maxSubArray2(vector<int>& nums)
//{
//    int sum = 0;
//    int res = std::numeric_limits<int>::min();
//    for (auto i = 0; i < nums.size(); ++i)
//    {
//        sum += nums[i];
//        res = sum > res ? sum : res;
//        sum = sum > 0 ? sum : 0;
//    }
//
//    return res;
//}
//
//void testMaxSubArray()
//{
//    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
//    cout << maxSubArray2(nums) << endl;
//}
//
//int main()
//{
//    testMaxSubArray();
//    getchar();
//}