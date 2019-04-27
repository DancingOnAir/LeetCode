#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canPartition(vector<int>& nums)
{
    int n = nums.size();
    if (n < 2)
        return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int mid = sum >> 1;
    if (sum & 1)
        return false;

    vector<bool> dp(mid + 1);
    dp[0] = true;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = mid; j > 0; --j)
        {
            if (j >= nums[i])
                dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[mid];
}

void testCanPartition()
{
    vector<int> nums1 = { 1, 5, 11, 5 };
    vector<int> nums2 = { 1, 2, 3, 5 };
    cout << (canPartition(nums1) ? "True" : "False") << endl;
    cout << (canPartition(nums2) ? "True" : "False") << endl;
}

int main()
{
    testCanPartition();

    getchar();
    return 0;
}