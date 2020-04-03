#include "pch.h"
#include "../BitManipulation/0260_SingleNumberIII.h"
using namespace testing;

class ASingleNumberIII : public Test
{
public:
    SingleNumberIIISolution solution;
};

TEST_F(ASingleNumberIII, AnswerEmptyNums)
{
    vector<int> emptyNums{};
    vector<int> expectRes{};

    ASSERT_EQ(solution.singleNumber(emptyNums), expectRes);
}

TEST_F(ASingleNumberIII, AnswerSixNums)
{
    vector<int> nums{ 1, 2, 1, 3, 2, 5 };
    vector<int> expectRes{3, 5};

    ASSERT_EQ(solution.singleNumber(nums), expectRes);
}
