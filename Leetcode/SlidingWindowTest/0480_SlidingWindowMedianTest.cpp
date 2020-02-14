#include "pch.h"
#include "../SlidingWindow/0480_SlidingWindowMedian.h"
using namespace testing;


//You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
//Answers within 10 ^ -5 of the actual value will be accepted as correct.
class ASlidingWindowMedian : public Test
{
public:
    Solution solution;
};

TEST_F(ASlidingWindowMedian, InputEmptyNumsReturnEmptyMedian)
{
    vector<int> emptyNums;
    vector<double> emptyAns;
    int k = 1;

    ASSERT_EQ(solution.medianSlidingWindow(emptyNums, k), emptyAns);
}

TEST_F(ASlidingWindowMedian, InputRegularNumsAndKIsOdd)
{
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<double> ans = { 1, -1, -1, 3, 5, 6 };
    int odd = 3;

    ASSERT_EQ(solution.medianSlidingWindow(nums, odd), ans);
}