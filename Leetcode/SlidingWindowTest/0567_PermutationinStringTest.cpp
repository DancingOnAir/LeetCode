#include "pch.h"
#include "../SlidingWindow/0567_PermutationinString.h"
using namespace testing;

class APermutationinString : public Test
{
public:
    Solution solution;
};

TEST_F(APermutationinString, InputS1IsEmptyReturnFalse)
{
    string noEmptyS2 = "abcd";
    ASSERT_FALSE(solution.checkInclusion("", noEmptyS2));
}

TEST_F(APermutationinString, InputS2IsEmptyReturnFalse)
{
    string noEmptyS1 = "abcd";
    ASSERT_FALSE(solution.checkInclusion(noEmptyS1, ""));
}

TEST_F(APermutationinString, InputSizeOfS2LessThanS1ReturnFalse)
{
    string s1With8Chars = "abcdefgh";
    string s2With4Chars = "abcd";
    ASSERT_FALSE(solution.checkInclusion(s1With8Chars, s2With4Chars));
}

TEST_F(APermutationinString, InputPermutatedS1IsSubstringOfS2RetureTrue)
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    ASSERT_TRUE(solution.checkInclusion(s1, s2));
}

TEST_F(APermutationinString, InputPermutatedS1IsNotSubstringOfS2RetureFalse)
{
    string s1 = "ab";
    string s2 = "eidboaoo";
    ASSERT_FALSE(solution.checkInclusion(s1, s2));
}