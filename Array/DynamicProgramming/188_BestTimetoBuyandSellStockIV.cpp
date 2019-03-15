//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxProfit(int k, vector<int>& prices)
//{
//    int len = prices.size();
//    if (len < 2)
//        return 0;
//
//    int res = 0;
//    if (k >= len / 2)
//    {
//        for (int i = 1; i < len; ++i)
//        {
//            res += max(prices[i] - prices[i - 1], 0);
//        }
//
//        return res;
//    }
//
//    vector<vector<int>> dp(k + 1, vector<int>(len));
//
//    for (int i = 1; i <= k; ++i)
//    {
//        int tmpMax = -prices[0];
//        for (int j = 1; j < len; ++j)
//        {
//            dp[i][j] = max(dp[i][j - 1], prices[j] + tmpMax);
//            tmpMax = max(tmpMax, dp[i - 1][j - 1] - prices[j]);
//        }
//    }
//
//    return dp[k][len - 1];
//}
//
//void testMaxProfit()
//{
//    vector<int> prices{ 3,2,6,5,0,3 };
//    int k = 2;
//
//    cout << maxProfit(k, prices) << endl;
//}
//
//int main()
//{
//    testMaxProfit();
//
//    getchar();
//    return 0;
//}