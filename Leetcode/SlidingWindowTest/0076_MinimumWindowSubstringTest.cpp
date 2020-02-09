#include "pch.h"
#include "../SlidingWindow/0076_MinimumWindowSubstring.h"

class MinimumWindowSubstring : public testing::Test
{
public:
    Solution solution;
    string s = "ADOBECODEBANC";
};

TEST_F(MinimumWindowSubstring, InputTIsEmpty)
{
    ASSERT_EQ(solution.minWindow(s, ""), "");
}

TEST_F(MinimumWindowSubstring, InputSSizeLessThanT)
{
    string t = "AAAAAAAAAAAAAAAAAAAAAA";

    ASSERT_EQ(solution.minWindow(s, t), "");
}

TEST_F(MinimumWindowSubstring, InputRegularString)
{
    string t = "ABC";
    string expect = "BANC";

    ASSERT_EQ(solution.minWindow(s, t), expect);
}

TEST_F(MinimumWindowSubstring, InputSAndTAreChar)
{
    ASSERT_EQ(solution.minWindow("a", "b"), "");
}