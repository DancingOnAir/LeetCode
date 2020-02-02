#include "pch.h"
#include "../String/0522_LongestUncommonSubsequenceII.h"

TEST(LongestUncommonSubsequenceIISolution, FindLUSlength)
{
    Solution solution;
    vector<string> strs1 = { "aa", "aaaa", "aaaa" };
    EXPECT_EQ(solution.findLUSlength(strs1), -1);

    vector<string> strs2 = { "aba", "cdc", "eae" };
    EXPECT_EQ(solution.findLUSlength(strs2), 3);

    vector<string> strs3 = { "aabbcc", "aabbcc","bc","bcc" };
    EXPECT_EQ(solution.findLUSlength(strs3), -1);

    vector<string> strs4 = { "abcabc", "abcabc", "abcabc", "abc", "abc", "cca" };
    EXPECT_EQ(solution.findLUSlength(strs4), 3);
}

