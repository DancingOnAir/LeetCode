#include "pch.h"
#include "../SegmentTree/0327_CountofRangeSum.h"
using namespace testing;

class ACountofRangeSum : public Test
{
public:
    Solution solution;
};

TEST_F(ACountofRangeSum, AnswerEmptyNums)
{
    ASSERT_EQ(solution.countRangeSum(vector<int>(), 0, 0), 0);
}

TEST_F(ACountofRangeSum, AnswerLowerGreaterThanUpper)
{
    vector<int> nums = { 1, 2, 3 };
    ASSERT_EQ(solution.countRangeSum(nums, nums.size() - 1, 0), 0);
}

TEST_F(ACountofRangeSum, AnswerNumsContainsThreeNums)
{
    vector<int> nums = { -2, 5, -1 };
    ASSERT_EQ(solution.countRangeSum(nums, -2, 2), 3);
}

TEST_F(ACountofRangeSum, AnswerNumsContainsSixNums)
{
    vector<int> nums = { 0, -3, -3, 1, 1, 2 };
    ASSERT_EQ(solution.countRangeSum(nums, 3, 5), 2);
}

