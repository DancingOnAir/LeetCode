#include "pch.h"
#include "../SegmentTree/0699_FallingSquares.h"
using namespace testing;

class AFallingSquares : public Test
{
public:
    Solution solution;
};

TEST_F(AFallingSquares, AnswerInputContainsThreeSquares)
{
    vector<vector<int>> positions{ {1, 2}, {2, 3}, {6, 1} };
    vector<int> expectHeights{ 2, 5, 5 };
    ASSERT_EQ(solution.fallingSquares(positions), expectHeights);
}
