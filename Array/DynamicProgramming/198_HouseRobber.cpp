#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums)
{
    int n = nums.size();
    if (0 == n)
        return 0;

    if (1 == n)
        return nums[0];

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }

    return dp[n];
}

void testRob()
{
    vector<int> nums = { 2,7,9,3,1 };
    cout << rob(nums) << endl;
}

int main()
{
    testRob();

    getchar();
    return 0;
}