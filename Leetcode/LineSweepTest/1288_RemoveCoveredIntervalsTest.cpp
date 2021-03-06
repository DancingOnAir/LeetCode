#include "pch.h"
#include "../LineSweep/1288_RemoveCoveredIntervals.h"
using namespace testing;

class RemoveCoveredIntervals : public Test
{
public:
    Solution solution;
};

TEST_F(RemoveCoveredIntervals, AnswerEmptyIntervals)
{
    vector<vector<int>> emptyIntervals;
    ASSERT_EQ(solution.removeCoveredIntervals(emptyIntervals), 0);
}

TEST_F(RemoveCoveredIntervals, AnswerThreeIntervalsCombineToTwo)
{
    vector<vector<int>> intervals = { {1, 4}, {3, 6}, {2, 8} };
    ASSERT_EQ(solution.removeCoveredIntervals(intervals), 2);
}
