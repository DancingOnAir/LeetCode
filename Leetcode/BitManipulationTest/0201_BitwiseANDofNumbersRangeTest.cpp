#include "pch.h"
#include "../BitManipulation/0201_BitwiseANDofNumbersRange.h"
using namespace testing;

class ABitwiseANDofNumbersRange : public Test
{
public:
    BitwiseANDofNumbersRangeSolution solution;
};

TEST_F(ABitwiseANDofNumbersRange, AnswerRangeContains3DigitsNums)
{
    int m = 5, n = 7;
    int expectRes = 4;

    ASSERT_EQ(solution.rangeBitwiseAnd(m, n), expectRes);
}

TEST_F(ABitwiseANDofNumbersRange, AnswerRangeContains1DigitsNums)
{
    int m = 0, n = 1;
    int expectRes = 0;

    ASSERT_EQ(solution.rangeBitwiseAnd(m, n), expectRes);
}

TEST_F(ABitwiseANDofNumbersRange, AnswerRangeContainsOnlyOneNum)
{
    int m = 3, n = 3;
    int expectRes = 3;

    ASSERT_EQ(solution.rangeBitwiseAnd(m, n), expectRes);
}