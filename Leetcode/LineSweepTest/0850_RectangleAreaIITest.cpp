#include "pch.h"
#include "../LineSweep/0850_RectangleAreaII.h"
using namespace testing;

class RectangleAreaII : public Test
{
public:
    Solution solution;
};

TEST_F(RectangleAreaII, Answer3Rectangles)
{
    vector<vector<int>> rectangles{ {0, 0, 2, 2},{1, 0, 2, 3},{1, 0, 3, 1} };
    ASSERT_EQ(solution.rectangleArea(rectangles), 6);
}