#include "pch.h"
#include "../SlidingWindow/0992_SubarrayswithKDifferentIntegers.h"

using namespace testing;

class ASubarrayswithKDifferentIntegers: public Test
{
public:
    Solution solution;
};

TEST_F(ASubarrayswithKDifferentIntegers, InputArrayContainsThreeDiffCharsAndKEquealTwo)
{
    vector<int> A = { 1, 2, 1, 2, 3 };
    int K = 2;

    ASSERT_EQ(solution.subarraysWithKDistinct(A, K), 7);
}

TEST_F(ASubarrayswithKDifferentIntegers, InputArrayContainsFourDiffCharsAndKEquealThree)
{
    vector<int> A = { 1, 2, 1, 3, 4 };
    int K = 3;

    ASSERT_EQ(solution.subarraysWithKDistinct(A, K), 3);
}
