#include "pch.h"
#include "../BitManipulation/0190_ReverseBits.h"
using namespace testing;

class AReverseBits : public Test
{
public:
    ReverseBitsSolution solution;
};

// 00000010100101000001111010011100 - 43261596
// 00111001011110000010100101000000 - 964176192
TEST_F(AReverseBits, AnswerRegularNum1)
{
    ASSERT_EQ(solution.reverseBits(43261596), 964176192);
}

// 11111111111111111111111111111101 - 4294967293
// 10111111111111111111111111111111 - 3221225471
TEST_F(AReverseBits, AnswerRegularNum2)
{
    ASSERT_EQ(solution.reverseBits(4294967293), 3221225471);
}
