#pragma once
#include <vector>
using namespace std;

const int NINF = 0xc0c0c0c0;

class SolutionIII
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        int k = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));

        for (int i = 0; i < n; ++i)
        {
            for (int j = k; j >= 1; --j)
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

    int maxProfit1(vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        int k = 3;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2)));

        for (int i = 0; i < k; ++i)
        {
            dp[0][i][0] = NINF;
            dp[0][i][1] = NINF;
        }
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < k; ++j)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return max(dp[n - 1][0][0], max(dp[n - 1][1][0], dp[n - 1][2][0]));
    }
};