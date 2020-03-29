#pragma once
#include <vector>

using namespace std;

class SolutionIV
{
public:
    int helper(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[0];
                continue;
            }

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }

    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        if (k > n / 2)
        {
            return helper(prices);
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int i = 0; i < n; ++i)
        {
            for (int j = k; j > 0; --j)
            {
                if (i == 0)
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};