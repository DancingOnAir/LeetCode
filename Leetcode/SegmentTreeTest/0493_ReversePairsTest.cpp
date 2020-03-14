#include "pch.h"
#include "../SegmentTree/0493_ReversePairs.h"
using namespace testing;

class AReversePairs : public Test
{
public:
    Solution solution;
};

TEST_F(AReversePairs, AnswerEmptyNums)
{
    ASSERT_EQ(solution.reversePairs(vector<int>()), 0);
}

TEST_F(AReversePairs, AnswerNumsContainsOnlyOneNum)
{
    vector<int> oneNums{ 1 };
    ASSERT_EQ(solution.reversePairs(oneNums), 0);
}

TEST_F(AReversePairs, AnswerNumsContainsFiveNumsReturnTwo)
{
    vector<int> fiveNums { 1, 3, 2, 3, 1 };
    ASSERT_EQ(solution.reversePairs(fiveNums), 2);
}

TEST_F(AReversePairs, AnswerNumsContainsFiveNumsReturnThree)
{
    vector<int> fiveNums{ 2, 4, 3, 5, 1 };
    ASSERT_EQ(solution.reversePairs(fiveNums), 3);
}

TEST_F(AReversePairs, AnswerNumsContainsTwoNegtiveNumsReturnOne)
{
    vector<int> twoNegtiveNums{ -5, -5 };
    ASSERT_EQ(solution.reversePairs(twoNegtiveNums), 1);
}
