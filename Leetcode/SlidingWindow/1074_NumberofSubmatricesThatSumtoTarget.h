#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1));
        //for (int i = 1; i <= m; ++i)
        //    presum[i][0] = matrix[i - 1][0] + presum[i - 1][0];

        //for (int i = 1; i <= n; ++i)
        //    presum[0][i] += matrix[0][i - 1] + presum[0][i - 1];

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                presum[i][j] = matrix[i - 1][j - 1] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
            }
        }

        int sum = 0, res = 0;
        for (int y1 = 1; y1 <= m; ++y1)
        {
            for (int x1 = 1; x1 <= n; ++x1)
            {
                for (int y2 = 0; y2 < y1; ++y2)
                {
                    for (int x2 = 0; x2 < x1; ++x2)
                    {
                        sum = presum[y1][x1] + presum[y2][x2] - presum[y1][x2] - presum[y2][x1];
                        if (sum == target)
                            ++res;
                    }
                }
            }
        }

        return res;
    }
};
