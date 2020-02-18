#include "pch.h"
#include "../SlidingWindow/0995_MinimumNumberofKConsecutiveBitFlips.h"

using namespace testing;

class AMinimumNumberofKConsecutiveBitFlips : public Test
{
public:
    Solution solution;
};

TEST_F(AMinimumNumberofKConsecutiveBitFlips, InputArrayWithThreeElementAndKEqOneReturnTwo)
{
    vector<int> A = { 0, 1, 0 };
    int K = 1;

    ASSERT_EQ(solution.minKBitFlips(A, K), 2);
}

TEST_F(AMinimumNumberofKConsecutiveBitFlips, InputArrayWithThreeElementAndKEqTwoReturnMinusOne)
{
    vector<int> A = { 1, 1, 0 };
    int K = 2;

    ASSERT_EQ(solution.minKBitFlips(A, K), -1);
}

TEST_F(AMinimumNumberofKConsecutiveBitFlips, InputArrayWithEightElementAndKEqThreeReturnThree)
{
    vector<int> A = { 0, 0, 0, 1, 0, 1, 1, 0 };
    int K = 3;

    ASSERT_EQ(solution.minKBitFlips(A, K), 3);
}
