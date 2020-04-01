#include "pch.h"
#include "../BitManipulation/0136_SingleNumber.h"
using namespace testing;

class ASingleNumber : public Test
{
public:
    SingleNumberSolution solution;
};

TEST_F(ASingleNumber, AnswerThreeNums)
{
    vector<int> nums{2, 2, 1};
    int singleNum = 1;

    ASSERT_EQ(solution.singleNumber(nums), singleNum);
}

TEST_F(ASingleNumber, AnswerFiveNums)
{
    vector<int> nums{ 4, 1, 2, 1, 2 };
    int singleNum = 4;

    ASSERT_EQ(solution.singleNumber(nums), singleNum);
}
