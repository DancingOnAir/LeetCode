//#include <iostream>
//#include <vector>
//
//#define max(a, b) ((a) > (b)? (a): (b))
//
//using namespace std;
//
//
//
//int maxCoins(vector<int>& nums)
//{
//    int n = nums.size();
//    nums.insert(nums.begin(), 1);
//    nums.emplace_back(1);
//
//    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int left = 1; left <= n - i + 1; ++left)
//        {
//            int right = left + i - 1;
//            for (int k = left; k <= right; ++k)
//            {
//                dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
//
//            }
//        }
//    }
//    return dp[1][n];
//}
//
//void testMaxCoins()
//{
//    vector<int> nums = { 3, 1, 5, 8 };
//    cout << maxCoins(nums) << endl;
//}
//
//int main()
//{
//    testMaxCoins();
//
//    getchar();
//    return 0;
//}