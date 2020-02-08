#include "pch.h"
#include "../SlidingWindow/0239_SlidingWindowMaximum.h"

TEST(SlidingWIndowMaximum, InputEmptyNums)
{
    vector<int> nums;
    vector<int> expect;
    int k = 3;

    Solution solution;
    ASSERT_EQ(solution.maxSlidingWindow(nums, k), expect);
}

TEST(SlidingWIndowMaximum, InputNumsSizeLessThanK)
{
    vector<int> nums = { 1, 3 };
    vector<int> expect;
    int k = 3;

    Solution solution;
    ASSERT_EQ(solution.maxSlidingWindow(nums, k), expect);
}

TEST(SlidingWIndowMaximum, InputEightNumsWithNegatives)
{
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<int> expect = { 3, 3, 5, 5, 6, 7 };
    int k = 3;

    Solution solution;
    ASSERT_EQ(solution.maxSlidingWindow(nums, k), expect);
}