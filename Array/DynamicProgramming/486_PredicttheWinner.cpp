#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool PredictTheWinner(vector<int>& nums)
{
    if (nums.size() < 2)
        return true;

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        dp[i][i] = nums[i];

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j + i < n; ++j)
        {
            dp[j][j + i] = max(nums[j + i] - dp[j][j + i - 1], nums[j] - dp[j + 1][j + i]);
        }
    }

    return dp[0][n - 1] >= 0;
}

void testPredictTheWinner()
{
    vector<int> nums1{ 1, 5, 2 };
    cout << (PredictTheWinner(nums1)?"T":"F") << endl;

    vector<int> nums2{ 1, 5, 233, 7 };
    cout << (PredictTheWinner(nums2) ? "T" : "F") << endl;
}

int main()
{
    testPredictTheWinner();

    getchar();
    return 0;
}