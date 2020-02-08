#include "pch.h"
#include "../SlidingWindow/0209_MinimumSizeSubarraySum.h"

TEST(MinimumSizeSubarraySum, InputEmptyNums)
{
    vector<int> nums;
    vector<int> expect;
    int k = 7;

    Solution solution;
    ASSERT_EQ(solution.minSubArrayLen(k, nums), 0);
}

TEST(MinimumSizeSubarraySum, InputNumsSizeLessThanK)
{
    vector<int> nums = { 2,3,1,2,4,3 };
    int k = 3;

    Solution solution;
    ASSERT_EQ(solution.minSubArrayLen(k, nums), 2);
}