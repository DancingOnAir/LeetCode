#pragma once
#include <vector>
using namespace std;

// i-th day 0 - n-1
// k-th trans 0 - m-1, increase 1 when buying stock, here k = 1
// 0 not holding stock, 1 holding stock
// dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i])
// dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][1] - price[i])
// dp[0][0][0] = 0
// dp[0][0][1] = NINF

const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
            return 0;

        int res = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // dp[i - 1][0][0] = 0, when k = 0
            dp[i][1] = max(dp[i - 1][1], - prices[i]);

        }
        return dp[n - 1][0];
    }
};