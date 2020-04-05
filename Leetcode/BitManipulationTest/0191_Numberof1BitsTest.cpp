#include "pch.h"
#include "../BitManipulation/0191_Numberof1Bits.h"

using namespace testing;

class ANumberof1Bits : public Test
{
public:
    Numberof1BitsSolution solution;
};

TEST_F(ANumberof1Bits, AnswerIntegerContainsThree1Bits)
{
    int num = 11;
    int expectRes = 3;

    ASSERT_EQ(solution.hammingWeight(num), expectRes);
}

TEST_F(ANumberof1Bits, AnswerIntegerContainsOnlyOne1Bit)
{
    int num = 128;
    int expectRes = 1;

    ASSERT_EQ(solution.hammingWeight(num), expectRes);
}