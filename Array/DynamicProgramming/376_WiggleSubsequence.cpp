#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int n = nums.size();
    if (1 == n)
        return 1;

    vector<int> greater(n, 1);
    vector<int> less(n, 1);

    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > nums[i - 1])
        {
            greater[i] = less[i - 1] + 1;
            less[i] = less[i - 1];
        }
        else if (nums[i] < nums[i - 1])
        {
            greater[i] = greater[i - 1];
            less[i] = greater[i - 1] + 1;
        }
        else
        {
            greater[i] = greater[i - 1];
            less[i] = less[i - 1];
        }
    }
    return max(greater[n - 1], less[n - 1]);

    //vector<vector<int>> dp(n, vector<int>(n));
    //for (int i = 0; i < n; ++i)
    //{
    //    dp[i][i] = 0;
    //}

    //for (int i = 0; i < n - 1; ++i)
    //{
    //    if (nums[i] != nums[i + 1])
    //        dp[i][i + 1] = 2;
    //    else
    //        dp[i][i + 1] = 1;
    //}

    //for (int i = 0; i < n - 2; ++i)
    //{
    //    for (int j = i + 2; j < n; ++j)
    //    {
    //        for (int k = j - 2; k >= i; --k)
    //        {
    //            if (dp[i][j - 1] == dp[i][k])
    //                continue;

    //            if ((nums[j - 1] > nums[j - 2] && nums[j] < nums[j - 1]) || (nums[j - 1] < nums[j - 2] && nums[j] > nums[j - 1]) || (dp[i][j - 1] == 1 && nums[j] != nums[j - 1]))
    //            {
    //                dp[i][j] = dp[i][j - 1] + 1;
    //            }
    //            else
    //            {
    //                dp[i][j] = dp[i][j - 1];
    //            }

    //        }
    //    }
    //}

    //return dp[0][n - 1];
}

void testWiggleMaxLength()
{
    vector<int> nums1{ 1,17,5,10,13,15,10,5,16,8 };
    vector<int> nums2{ 3, 3, 3, 2, 5 };
    cout << wiggleMaxLength(nums1) << endl;
}

int main()
{
    testWiggleMaxLength();

    getchar();
    return 0;
}