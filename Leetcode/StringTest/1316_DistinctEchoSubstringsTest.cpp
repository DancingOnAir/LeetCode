#include "pch.h"
#include "../String/1316_DistinctEchoSubstrings.h"

TEST(DistinctEchoSubstrings, InputWordContainOnlyOneChar)
{
    Solution solution;
    string s = "a";
    EXPECT_EQ(solution.distinctEchoSubstrings(s), 0);
}

TEST(DistinctEchoSubstrings, InputWordContainThreeRepeatSubstrings)
{
    Solution solution;
    string s = "abcabcabc";
    EXPECT_EQ(solution.distinctEchoSubstrings(s), 3);
}

TEST(DistinctEchoSubstrings, InputRegularWord)
{
    Solution solution;
    string s = "leetcodeleetcode";
    EXPECT_EQ(solution.distinctEchoSubstrings(s), 2);
}