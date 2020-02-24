#include "pch.h"
#include "../LineSweep/0218_TheSkylineProblem.h"

using namespace testing;

class ATheSkylineProblem : public Test
{
public:
    Solution solution;
};

TEST_F(ATheSkylineProblem, AnswerBuildingContains5)
{
    vector<vector<int>> buildings{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> expectSkyline{ {2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0} };

    ASSERT_EQ(solution.getSkyline(buildings), expectSkyline);
}
