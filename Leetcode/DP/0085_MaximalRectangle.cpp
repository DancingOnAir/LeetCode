#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

static int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


void updateArea(vector<vector<vector<int>>>& dp, int i, int j)
{
    int minA = dp[i][j][0];
    int row = dp[i][j][1];

    for (int count = 0; count < row; ++count)
    {
        minA = std::min(minA, dp[i - count][j][0]);
        dp[i][j][2] = std::max(dp[i][j][2], minA * (count + 1));
    }
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    int m = matrix.size();
    if (!m)
        return 0;

    int n = matrix[0].size();
    if (!n)
        return 0;

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, 0)));
    int res = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == '0')
                ;
            else
            {
                if (0 == i && 0 == j)
                    dp[i][j] = { 1, 1, 1 };
                else if (0 == i)
                    dp[i][j] = { dp[i][j - 1][0] + 1, 1, dp[i][j - 1][2] + 1 };
                else if (0 == j)
                    dp[i][j] = { 1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1 };
                else
                {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                    updateArea(dp, i, j);
                }
            }

            res = std::max(res, dp[i][j][2]);
        }
    }

    return res;
}

void testMaximalRectangle()
{
    vector<vector<char>> matrix = { {'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'} };

    cout << maximalRectangle(matrix) << endl;

}

int main()
{
    testMaximalRectangle();

    getchar();
    return 0;
}