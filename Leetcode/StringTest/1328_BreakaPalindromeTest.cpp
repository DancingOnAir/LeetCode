#include "pch.h"
#include "../String/1328_BreakaPalindrome.h"

TEST(BreakPalindrome, InputEmptyString)
{
    Solution solution;
    string s1 = "";

    ASSERT_EQ(solution.breakPalindrome(s1), "");
}

TEST(BreakPalindrome, InputOnlyOneChar)
{
    Solution solution;
    string s1 = "c";

    ASSERT_EQ(solution.breakPalindrome(s1), "");
}

TEST(BreakPalindrome, InputRegularPalindrome)
{
    Solution solution;
    string s1 = "abccba";

    ASSERT_EQ(solution.breakPalindrome(s1), "aaccba");
}

TEST(BreakPalindrome, InputPalindromeComprisedByA)
{
    Solution solution;
    string s1 = "aaaaaa";

    ASSERT_EQ(solution.breakPalindrome(s1), "aaaaab");
}

TEST(BreakPalindrome, InputSpecialPalindrome)
{
    Solution solution;

    string s1 = "aba";
    EXPECT_EQ(solution.breakPalindrome(s1), "abb");
}
