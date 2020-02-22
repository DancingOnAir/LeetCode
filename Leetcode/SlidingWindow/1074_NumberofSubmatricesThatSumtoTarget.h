#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // TLE
    int numSubmatrixSumTarget2(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1));

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

    // 2d presum, sliding window
    int numSubmatrixSumTarget1(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                presum[i][j] = matrix[i - 1][j - 1] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
            }
        }

        int res = 0;
        for (int left = 0; left <= n; ++left)
        {
            for (int right = left + 1; right <= n; ++right)
            {
                unordered_map<int, int> counter;
                int sum = 0;

                for (int k = 1; k <= m; ++k)
                {
                    sum = presum[k][right] + presum[0][left] - presum[k][left] - presum[0][right];
                    if (target == sum)
                        ++res;

                    if (counter.count(sum - target))
                        res += counter[sum - target];

                    counter[sum]++;
                }
            }
        }

        return res;
    }

    // 1d presum & sliding window
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for (int left = 0; left < n; ++left)
        {
            vector<int> presumRows(m);
            for (int right = left; right < n; ++right)
            {
                for (int i = 0; i < m; ++i)
                    presumRows[i] += matrix[i][right];

                int sum = 0;
                unordered_map<int, int> visited;
                for (int i = 0; i < m; ++i)
                {
                    visited[sum]++;
                    sum += presumRows[i];
 
                    if (visited.count(sum - target))
                        res += visited[sum - target];
                }
            }
        }

        return res;
    }
};
