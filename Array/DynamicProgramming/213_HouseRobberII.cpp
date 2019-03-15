#include <iostream>
#include <vector>
//#include <algorithm>

#define max(a, b) ((a) > (b) ? (a):(b))
using namespace std;

int helper(vector<int>& nums, int lo, int hi)
{
    int n = hi - lo + 1;
    if (n < 2)
        return n ? nums[lo] : 0;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[lo];

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + lo - 1]);
    }

    return dp[n];
}

int rob(vector<int>& nums)
{
    int n = nums.size();

    if (n < 2)
        return n ? nums[0] : 0;

    return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
}

void testRob()
{
    vector<int> nums = { 1, 2};
    cout << rob(nums) << endl;
}

int main()
{
    testRob();

    getchar();
    return 0;
}