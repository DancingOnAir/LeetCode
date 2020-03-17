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

TEST_F(AFallingSquares, AnswerInputContainsTwoSquaresWithLeftAdjacent)
{
    vector<vector<int>> positions{ {100, 100}, {200, 100} };
    vector<int> expectHeights{ 100, 100 };
    ASSERT_EQ(solution.fallingSquares(positions), expectHeights);
}

TEST_F(AFallingSquares, AnswerInputContainsTwoSquaresWithRightAdjacent)
{
    vector<vector<int>> positions{ {6, 1}, {9, 2}, {2, 4} };
    vector<int> expectHeights{ 1, 2, 4 };
    ASSERT_EQ(solution.fallingSquares(positions), expectHeights);
}

TEST_F(AFallingSquares, AnswerInputContainsThreeSquaresFailCase)
{
    vector<vector<int>> positions{ {1, 5}, {2, 2}, {7, 5}};
    vector<int> expectHeights{ 5, 7, 7 };
    ASSERT_EQ(solution.fallingSquares(positions), expectHeights);
}
