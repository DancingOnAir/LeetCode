#include "pch.h"
#include "../SegmentTree/1353_MaximumNumberofEventsThatCanBeAttended.h"

using namespace testing;

class AMaximumNumberofEventsThatCanBeAttended: public Test
{
public:
    Solution solution;
};

TEST_F(AMaximumNumberofEventsThatCanBeAttended, AnswerEventsContainsFourEvent)
{
    vector<vector<int>> events{{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    int expect = 4;

    ASSERT_EQ(solution.maxEvents(events), expect);
}

TEST_F(AMaximumNumberofEventsThatCanBeAttended, AnswerEventsContainsFiveEvent)
{
    vector<vector<int>> events{{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};
    int expect = 4;

    ASSERT_EQ(solution.maxEvents(events), expect);
}

TEST_F(AMaximumNumberofEventsThatCanBeAttended, AnswerEventsContainsOneEvent)
{
    vector<vector<int>> events{{1, 100000}};
    int expect = 1;

    ASSERT_EQ(solution.maxEvents(events), expect);
}

TEST_F(AMaximumNumberofEventsThatCanBeAttended, AnswerEventsContainsSevenEvent)
{
    vector<vector<int>> events{{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}};
    int expect = 7;

    ASSERT_EQ(solution.maxEvents(events), expect);
}
