#pragma once
#include <vector>
using namespace std;

const int NINF = 0xc0c0c0c0;

class SolutionII {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }

    // This is the original solution for q0122, but TLE.
    // here, the transaction times: trans = infinity, so dp[i][k][0] == dp[i][k - 1][0]
    // explation, 1st, from the mathematical point of view, limit(trans) = limit(trans - 1),
    //            2nd, if trans = infinity, it cannot be the constraints.
    // as the conclusion, the trans dimension can be optimized, means ignore.
    int maxProfit1(vector<int>& prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;

        int trans = n / 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(trans + 1, vector<int>(2, 0)));

        for (int i = 0; i <= trans; ++i)
        {
            dp[0][i][0] = NINF;
            dp[0][i][1] = NINF;
        }

        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= trans; ++j)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        int res = 0;
        for (int i = 0; i <= trans; ++i)
            res = max(res, dp[n - 1][i][0]);

        return res;
    }
};