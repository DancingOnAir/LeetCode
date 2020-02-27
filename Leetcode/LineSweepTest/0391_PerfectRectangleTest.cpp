#include "pch.h"
#include "../LineSweep/0391_PerfectRectangle.h"
using namespace testing;

class APerfectRectangle : public Test
{
public:
    Solution solution;
};

TEST_F(APerfectRectangle, Answer5RectanglesFormARectangularRegion)
{
    vector<vector<int>> rectangles = { {1, 1, 3, 3},
                                    {3, 1, 4, 2},
                                    {3, 2, 4, 4},
                                    {1, 3, 2, 4},
                                    {2, 3, 3, 4} };
    ASSERT_TRUE(solution.isRectangleCover(rectangles));
}

TEST_F(APerfectRectangle, AnswerAGapBetween2Rectangles)
{
    vector<vector<int>> rectangles = { {1, 1, 2, 3},
                                    {1, 3, 2, 4},
                                    {3, 1, 4, 2},
                                    {3, 2, 4, 4} };
    ASSERT_FALSE(solution.isRectangleCover(rectangles));
}

TEST_F(APerfectRectangle, AnswerAGapInTheTopCenter)
{
    vector<vector<int>> rectangles = { {1, 1, 3, 3},
                                    {3, 1, 4, 2},
                                    {1, 3, 2, 4},
                                    {3, 2, 4, 4} };
    ASSERT_FALSE(solution.isRectangleCover(rectangles));
}

TEST_F(APerfectRectangle, Answer2RectanglesOverlapEachOther)
{
    vector<vector<int>> rectangles = { {1, 1, 3, 3},
                                    {3, 1, 4, 2},
                                    {1, 3, 2, 4},
                                    {2, 2, 4, 4} };
    ASSERT_FALSE(solution.isRectangleCover(rectangles));
}