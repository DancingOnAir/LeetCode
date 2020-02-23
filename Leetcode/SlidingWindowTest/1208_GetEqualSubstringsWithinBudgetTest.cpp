#include "pch.h"
#include "../SlidingWindow/1208_GetEqualSubstringsWithinBudget.h"
using namespace testing;

class GetEqualSubstringsWithinBudget : public Test
{
public:
    Solution solution;
};

TEST_F(GetEqualSubstringsWithinBudget, AnswerStringContain4CharsAndMaxCostEq3Return3)
{
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;

    ASSERT_EQ(solution.equalSubstring(s, t, maxCost), 3);
}

TEST_F(GetEqualSubstringsWithinBudget, AnswerStringContain4CharsAndMaxCostEq3Return1)
{
    string s = "abcd";
    string t = "cdef";
    int maxCost = 3;

    ASSERT_EQ(solution.equalSubstring(s, t, maxCost), 1);
}

TEST_F(GetEqualSubstringsWithinBudget, AnswerStringContain4CharsAndMaxCostEq0Return1)
{
    string s = "abcd";
    string t = "acde";
    int maxCost = 0;

    ASSERT_EQ(solution.equalSubstring(s, t, maxCost), 1);
}

TEST_F(GetEqualSubstringsWithinBudget, AnswerStringContain15CharsAndMaxCostEq14Return4)
{
    string s = "krpgjbjjznpzdfy";
    string t = "nxargkbydxmsgby";
    int maxCost = 14;

    ASSERT_EQ(solution.equalSubstring(s, t, maxCost), 4);
}
