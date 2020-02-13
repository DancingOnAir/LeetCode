#include "pch.h"
#include "../SlidingWindow/0978_LongestTurbulentSubarray.h"

using namespace testing;

class ALongestTurbulentSubarray : public Test
{
public:
    Solution solution;
};

TEST_F(ALongestTurbulentSubarray, InputEmptyNumsReturnZero)
{
    vector<int> emptyNums;
    ASSERT_EQ(solution.maxTurbulenceSize(emptyNums), 0);
}

TEST_F(ALongestTurbulentSubarray, InputOnlyOneNumReturnOne)
{
    vector<int> oneNum{ 100 };
    ASSERT_EQ(solution.maxTurbulenceSize(oneNum), 1);
}

TEST_F(ALongestTurbulentSubarray, InputTwoEqualNumsReturnOne)
{
    vector<int> twoEqualNum{ 1, 1 , 1};
    ASSERT_EQ(solution.maxTurbulenceSize(twoEqualNum), 1);
}

TEST_F(ALongestTurbulentSubarray, InputRegularNumsWithFiveTurbulentSubarray)
{
    vector<int> nums{ 9, 4, 2, 10, 7, 8, 8, 1, 9 };
    ASSERT_EQ(solution.maxTurbulenceSize(nums), 5);
}

TEST_F(ALongestTurbulentSubarray, LeetcodeFailureCase)
{
    vector<int> nums{ 0, 8, 45, 88, 48, 68, 28, 55, 17, 24 };
    ASSERT_EQ(solution.maxTurbulenceSize(nums), 8);
}