#pragma once
#include <vector>

using namespace std;

const int NINF = 0xc0c0c0c0;

class SolutionV
{
public:
    // consider 2nd condition for dp[day][status], status = buy, sell & cooldown, size = 3
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = NINF;

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }

        return max(dp[n - 1][0], dp[n - 1][2]);
    }

    // coz the cooldown for buying stock after sell the stock.
    // dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    int maxProfit1(vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(0, prices[1] - prices[0]);
        dp[1][1] = max(-prices[0], -prices[1]);

        for (int i = 2; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};