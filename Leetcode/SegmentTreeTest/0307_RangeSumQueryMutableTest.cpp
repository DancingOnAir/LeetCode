#include "pch.h"
#include "../SegmentTree/0307_RangeSumQueryMutable.h"
using namespace testing;

class ARangeSumQueryMutable : public Test
{
public:
    virtual void SetUp()
    {
        nums = { 1, 3, 5 };
        pNumArray = new NumArray(nums);
    }

    virtual void TearDown()
    {
        delete pNumArray;
    }

protected:
    vector<int> nums;
    NumArray* pNumArray;
};

TEST_F(ARangeSumQueryMutable, AnswerEmptyNumArray)
{
    NumArray emptyNumArray = NumArray(vector<int>());
    ASSERT_EQ(emptyNumArray.sumRange(0, 0), 0);
}

TEST_F(ARangeSumQueryMutable, AnswerTotalSum)
{
    int n = nums.size();
    int expectSum = 0;
    for (int x : nums)
        expectSum += x;

    ASSERT_EQ(pNumArray->sumRange(0, n - 1), expectSum);
}

TEST_F(ARangeSumQueryMutable, AnswerUpdateVal)
{
    int n = nums.size();
    pNumArray->update(1, 2);
    nums[1] = 2;

    int expectSum = 0;
    for (int x : nums)
        expectSum += x;

    ASSERT_EQ(pNumArray->sumRange(0, n - 1), expectSum);
}
