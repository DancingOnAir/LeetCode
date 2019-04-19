#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool doable(const vector<int>& nums, int cuts, long long max)
{
    int acc = 0;
    for (int x : nums)
    {
        if (x > max)
            return false;

        else if (acc + x <= max)
            acc += x;
        else
        {
            --cuts;
            acc = x;
            if (cuts < 0)
                return false;
        }
    }

    return true;
}

int splitArray(vector<int>& nums, int m)
{
    long long left = 0, right = 0;

    for (int x : nums)
    {
        left = max(left, (long long)x);
        right += x;
    }

    while (left < right)
    {
        long long mid = left + (right - left) / 2;
        if (doable(nums, m - 1, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int splitArray2(vector<int>& nums, int m)
{
    int n = nums.size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = nums[0];

    for (int i = 1; i < n; ++i)
        dp[0][i] = dp[0][i - 1] + nums[i];

    for (int k = 1; k < m; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            int minVal = dp[0][i];
            for (int j = i - 1; j >= 0; --j)
            {
                int tmpVal = max(dp[0][i] - dp[0][j], dp[k - 1][j]);
                minVal = min(minVal, tmpVal);
            }

            dp[k][i] = minVal;
        }
    }

    return dp[m - 1][n - 1];
}

void testSplitArray()
{
    vector<int> nums1 = { 7,2,5,10,8 };
    int m1 = 2;

    vector<int> nums2 = { 1,2147483646 };
    int m2 = 1;

    vector<int> nums3 = { 1, 2, 3, 4, 5 };
    int m3 = 2;
    cout << splitArray2(nums3, m3) << endl;
}

int main()
{
    testSplitArray();

    getchar();
    return 0;
}