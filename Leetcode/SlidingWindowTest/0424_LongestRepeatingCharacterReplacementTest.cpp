#include "pch.h"
#include "../SlidingWindow/0424_LongestRepeatingCharacterReplacement.h"
using namespace testing;

class LongestRepeatingCharacterReplacement : public Test
{
public:
    Solution solution;
};

TEST_F(LongestRepeatingCharacterReplacement, InputEmptyStringGetZeroResult)
{
    int operationTimes = 3;

    ASSERT_EQ(solution.characterReplacement("", operationTimes), 0);
}

TEST_F(LongestRepeatingCharacterReplacement, InputOperationTimesNotLessThanSizeOfString)
{
    string s = "ABCDE";
    int operationTimes = s.size();

    ASSERT_EQ(solution.characterReplacement(s, operationTimes), s.size());
}

TEST_F(LongestRepeatingCharacterReplacement, InputRegularStringAndOperationTImesLessThanSizeOfString)
{
    string s = "AAAAA";
    int operationTimes = 0;

    ASSERT_EQ(solution.characterReplacement(s, operationTimes), 5);
}
