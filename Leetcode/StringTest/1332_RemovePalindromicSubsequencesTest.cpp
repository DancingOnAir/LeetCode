#include "pch.h"
#include "../String/1332_RemovePalindromicSubsequences.h"

TEST(RemovePalindromeSub, InputEmptyString)
{
    Solution solution;
    
    string s1;
    EXPECT_EQ(solution.removePalindromeSub(s1), 0);
}

TEST(RemovePalindromeSub, InputRegularString)
{
    Solution solution;

    string s1 = "ababa";
    EXPECT_EQ(solution.removePalindromeSub(s1), 1);

    string s2 = "abb";
    EXPECT_EQ(solution.removePalindromeSub(s2), 2);

    string s3 = "baabb";
    EXPECT_EQ(solution.removePalindromeSub(s3), 2);
}