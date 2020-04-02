#include "pch.h"
#include "../BitManipulation/0137_SingleNumberII.h"
using namespace testing;

class ASingleNumberII : public Test
{
public:
    SingleNumberIISolution solution;
};

TEST_F(ASingleNumberII, AnswerFourNums)
{
    vector<int> nums{ 2, 2, 3, 2 };
    int singleNum = 3;

    ASSERT_EQ(solution.singleNumber(nums), singleNum);
}

TEST_F(ASingleNumberII, AnswerSevenNums)
{
    vector<int> nums{ 0, 1, 0, 1, 0, 1, 99 };
    int singleNum = 99;

    ASSERT_EQ(solution.singleNumber(nums), singleNum);
}

//TEST_F(ASingleNumberII, AnswerSevenNums)
//{
//    vector<int> nums{ 43, 16, 45, 89, 45, -2147483648, 45, 2147483646, -2147483647, -2147483648, 43, 2147483647, -2147483646, -2147483648, 89, -2147483646, 89, -2147483646, -2147483647, 2147483646, -2147483647, 16, 16, 2147483646, 43 };
//    int singleNum = 99;
//
//    ASSERT_EQ(solution.singleNumber(nums), singleNum);
//}