#include "pch.h"
#include "../SlidingWindow/0003_LongestSubstringWithoutRepeatingCharacters.h"

class LongestSubstringWithoutRepeatingCharacters : public testing::Test
{
public:
    Solution solution;
};

TEST_F(LongestSubstringWithoutRepeatingCharacters, InputStringIsEmpty)
{
    string s = "";

    ASSERT_EQ(solution.lengthOfLongestSubstring(s), 0);
}

TEST_F(LongestSubstringWithoutRepeatingCharacters, InputStringCompriseBySameChar)
{
    string s = "bbbbbb";

    ASSERT_EQ(solution.lengthOfLongestSubstring(s), 1);
}

TEST_F(LongestSubstringWithoutRepeatingCharacters, InputRegularString)
{
    string s = "abcabcbb";

    ASSERT_EQ(solution.lengthOfLongestSubstring(s), 3);
}