#include "pch.h"
#include "../SlidingWindow/1004_MaxConsecutiveOnesIII.h"
using namespace testing;

class MaxConsecutiveOnesIII : public Test
{
public:
    Solution solution;
};

TEST_F(MaxConsecutiveOnesIII, AnswerRegularStringAndKEqTwo)
{
    vector<int> A { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int K = 2;
    ASSERT_EQ(solution.longestOnes(A, K), 6);
}

TEST_F(MaxConsecutiveOnesIII, AnswerRegularStringAndKEqThree)
{
    vector<int> A { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int K = 3;
    ASSERT_EQ(solution.longestOnes(A, K), 10);
}
