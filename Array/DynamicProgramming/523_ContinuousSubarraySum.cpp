#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (nums[i] == 0 && nums[i + 1] == 0)
            return true;
    }

    if (0 == k)
        return false;

    if (k < 0)
        k = -k;

    int sum = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
        dp[i][i] = nums[i];
        for (int j = i + 1; j < n; ++j)
        {
            dp[i][j] = dp[i][j - 1] + nums[j];
            if (dp[i][j] % k == 0)
                return true;
        }

    }
    return false;
}

bool checkSubarraySum2(vector<int>& nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (nums[i] == 0 && nums[i + 1] == 0)
            return true;
    }

    if (0 == k)
        return false;

    if (k < 0)
        k = -k;

    unordered_set<int> m;
    int sum = 0, pre = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
        int temp = k == 0 ? 0 : (sum % k);
        if (m.count(temp))
            return true;

        m.insert(pre);
        pre = temp;
    }

    return false;
}

void testCheckSubarraySum()
{
    vector<int> nums1 = { 23, 2, 4, 6, 7 };
    int k1 = 6;

    vector<int> nums2 = { 23, 6, 9 };
    int k2 = 6;

    cout << (checkSubarraySum2(nums1, k1) ? "T" : "F") << endl;
    cout << (checkSubarraySum2(nums2, k2) ? "T" : "F") << endl;
}

int main()
{
    testCheckSubarraySum();

    getchar();
    return 0;
}