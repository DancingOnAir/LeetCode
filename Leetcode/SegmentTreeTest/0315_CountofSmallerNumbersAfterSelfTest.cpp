#include "pch.h"
#include "../SegmentTree/0315_CountofSmallerNumbersAfterSelf.h"
using namespace testing;

class ACountofSmallerNumbersAfterSelf : public Test
{
public:
    Solution solution;
};

TEST_F(ACountofSmallerNumbersAfterSelf, AnswerEmptyNums)
{
    ASSERT_EQ(solution.countSmaller(vector<int>()), vector<int>());
}

TEST_F(ACountofSmallerNumbersAfterSelf, AnswerNumsContainsOnlyOneNum)
{
    vector<int> nums{ 1 };
    ASSERT_EQ(solution.countSmaller(nums), vector<int>{0});
}

TEST_F(ACountofSmallerNumbersAfterSelf, AnswerNumsContainsFourNums)
{
    vector<int> nums { 5, 2, 6, 1 };
    vector<int> expectCounts { 2, 1, 1, 0 };
    ASSERT_EQ(solution.countSmaller(nums), expectCounts);
}
