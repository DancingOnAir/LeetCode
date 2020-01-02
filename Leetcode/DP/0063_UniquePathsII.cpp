#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n));

    for (int i = 0; i < m; ++i)
    {
        if (!obstacleGrid[i][0])
            dp[i][0] = 1;
        else
            break;
    }

    for (int j = 0; j < n; ++j)
    {
        if (!obstacleGrid[0][j])
            dp[0][j] = 1;
        else
            break;
    }

    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (!obstacleGrid[i][j])
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<long long> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (!obstacleGrid[0][i])
            dp[i] = 1;
        else
            break;
    }

    for (int i = 1; i < m; ++i)
    {
        if (obstacleGrid[i][0])
            dp[0] = 0;

        for (int j = 1; j < n; ++j)
        {
            if (!obstacleGrid[i][j])
                dp[j] += dp[j - 1];
            else
                dp[j] = 0;
        }
    }

    return dp[n - 1];
}

void testUniquePathsWithObstacles()
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}

int main()
{
    testUniquePathsWithObstacles();

    getchar();
    return 0;
}