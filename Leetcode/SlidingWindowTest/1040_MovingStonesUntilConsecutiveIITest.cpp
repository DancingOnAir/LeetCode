#include "pch.h"
#include "../SlidingWindow/1040_MovingStonesUntilConsecutiveII.h"
using namespace testing;

class AMovingStonesUntilConsecutiveII : public Test
{
public:
    Solution solution;
};

TEST_F(AMovingStonesUntilConsecutiveII, AnswerArrayContains3Elements)
{
    vector<int> stones{ 7, 4, 9 };
    vector<int> expect{ 1, 2 };

    ASSERT_EQ(solution.numMovesStonesII(stones), expect);
}

TEST_F(AMovingStonesUntilConsecutiveII, AnswerArrayContains5Elements)
{
    vector<int> stones{ 6, 5, 4, 3, 10 };
    vector<int> expect{ 2, 3 };

    ASSERT_EQ(solution.numMovesStonesII(stones), expect);
}

TEST_F(AMovingStonesUntilConsecutiveII, AnswerArrayContainsContinuous5Elements)
{
    vector<int> stones{ 100, 101, 104, 102, 103 };
    vector<int> expect{ 0, 0 };

    ASSERT_EQ(solution.numMovesStonesII(stones), expect);
}