#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int removeSubBoxes(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int>>>& dp)
{
    if (i > j)
        return 0;

    if (dp[i][j][k] > 0)
        return dp[i][j][k];

    for (; i + 1 <= j && boxes[i + 1] == boxes[i]; ++i, ++k)
    {
        ;
    }

    int res = (k + 1) * (k + 1) + removeSubBoxes(boxes, i + 1, j, 0, dp);

    for (int m = i + 1; m <= j; ++m)
    {
        if (boxes[i] == boxes[m])
        {
            res = max(res, removeSubBoxes(boxes, i + 1, m - 1, 0, dp) + removeSubBoxes(boxes, m, j, k + 1, dp));
        }
    }

    dp[i][j][k] = res;
    return res;
}

int removeBoxes(vector<int>& boxes)
{
    int n = boxes.size();
    if (n < 2)
        return n;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
    return removeSubBoxes(boxes, 0, n - 1, 0, dp);
}

void testRemoveBoxes()
{
    vector<int> boxes = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };
    cout << removeBoxes(boxes) << endl;
}

int main()
{
    testRemoveBoxes();

    getchar();
    return 0;
}