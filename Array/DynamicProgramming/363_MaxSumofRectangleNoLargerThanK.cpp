#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int row = matrix.size();
    int col = matrix[0].size();
    int res = INT_MIN;

    for (int l = 0; l < col; ++l)
    {
        vector<int> sums(row);

        for (int j = l; j < col; ++j)
        {
            for (int i = 0; i < row; ++i)
            {
                sums[i] += matrix[i][j];
            }

            set<int> s;
            s.insert(0);

            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums)
            {
                curSum += sum;
                auto iter = s.lower_bound(curSum - k);

                if (iter != s.end())
                    curMax = max(curMax, curSum - *iter);

                s.insert(curSum);
            }

            res = max(res, curMax);
        }
    }

    return res;
}

void testMaxSumSubmatrix()
{
    vector<vector<int>> matrix = { {1, 0, 1}, { 0, -2, 3} };
    int k = 2;

    cout << maxSumSubmatrix(matrix, k) << endl;
}

int main()
{
    testMaxSumSubmatrix();

    getchar();
    return 0;
}