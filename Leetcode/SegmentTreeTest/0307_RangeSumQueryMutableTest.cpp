#include "pch.h"
#include "../SegmentTree/0307_RangeSumQueryMutable.h"
using namespace testing;

class ARangeSumQueryMutable : public Test
{
public:
    virtual void SetUp()
    {
        pEmptyNumArray = new NumArray(emptyNums);

        threeNums = { 1, 3, 5 };
        pNumArrayContainsThreeNums = new NumArray(threeNums);

        fiveNums = { 0, 9, 5, 7, 3 };
        pNumArrayContainsFiveNums = new NumArray(fiveNums);
    }

    virtual void TearDown()
    {
        delete pEmptyNumArray;
        delete pNumArrayContainsThreeNums;
        delete pNumArrayContainsFiveNums;
    }

protected:
    vector<int> threeNums;
    vector<int> fiveNums;
    vector<int> emptyNums;
    NumArray* pNumArrayContainsThreeNums;
    NumArray* pNumArrayContainsFiveNums;
    NumArray* pEmptyNumArray;
};

TEST_F(ARangeSumQueryMutable, AnswerEmptyNumArray)
{
    ASSERT_EQ(pEmptyNumArray->sumRange(0, 0), 0);
}

TEST_F(ARangeSumQueryMutable, AnswerThreeNumsTotalSum)
{
    int n = threeNums.size();
    int expectSum = 0;
    for (int x : threeNums)
        expectSum += x;

    ASSERT_EQ(pNumArrayContainsThreeNums->sumRange(0, n - 1), expectSum);
}

TEST_F(ARangeSumQueryMutable, AnswerThreeNumsUpdateVal)
{
    int n = threeNums.size();
    pNumArrayContainsThreeNums->update(1, 2);

    threeNums[1] = 2;
    int expectSum = 0;
    for (int x : threeNums)
        expectSum += x;

    ASSERT_EQ(pNumArrayContainsThreeNums->sumRange(0, n - 1), expectSum);
}

TEST_F(ARangeSumQueryMutable, AnswerFiveNumsSum)
{
    int n = fiveNums.size();
    int expectSum = 0;
    for (int x : fiveNums)
        expectSum += x;

    EXPECT_EQ(pNumArrayContainsFiveNums->sumRange(2, 4), 15);
    EXPECT_EQ(pNumArrayContainsFiveNums->sumRange(0, n - 1), expectSum);
}

TEST_F(ARangeSumQueryMutable, AnswerFiveNumsUpdateVal)
{
    int n = fiveNums.size();
    pNumArrayContainsFiveNums->update(1, 2);

    fiveNums[1] = 2;
    int expectSum = 0;
    for (int x : fiveNums)
        expectSum += x;

    ASSERT_EQ(pNumArrayContainsFiveNums->sumRange(0, n - 1), expectSum);
}
