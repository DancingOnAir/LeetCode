#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    if (0 == m || 0 == n)
        return 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (1 == i || 1== j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}

void testUniquePaths()
{
    int m1 = 3, n1 = 2;
    cout << uniquePaths(m1, n1) << endl;

    int m2 = 7, n2 = 3;
    cout << uniquePaths(m2, n2) << endl;
}

int main()
{
    testUniquePaths();

    getchar();
    return 0;
}