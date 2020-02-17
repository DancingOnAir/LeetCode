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

