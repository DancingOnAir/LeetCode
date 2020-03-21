#include "pch.h"
#include "../SegmentTree/1157_OnlineMajorityElementInSubarray.h"
using namespace testing;

class AOnlineMajorityElementInSubarray : public Test
{
public:
    virtual void SetUp()
    {
        vector<int> arr{ 1, 1, 2, 2, 1, 1 };
        majorityChecker_ = new MajorityChecker(arr);
    }

    virtual void TearDown()
    {
        delete majorityChecker_;
    }

protected:
    MajorityChecker* majorityChecker_;
};

TEST_F(AOnlineMajorityElementInSubarray, AnswerSatisfyThresholdFour)
{
    int left = 0;
    int right = 5;
    int threshold = 4;
    int expect = 1;
    ASSERT_EQ(majorityChecker_->query(left, right, threshold), expect);
}

TEST_F(AOnlineMajorityElementInSubarray, AnswerNoSatisfyThresholdThree)
{
    int left = 0;
    int right = 3;
    int threshold = 3;
    int expect = -1;
    ASSERT_EQ(majorityChecker_->query(left, right, threshold), expect);
}

TEST_F(AOnlineMajorityElementInSubarray, AnswerSatisfyThresholdTwo)
{
    int left = 2;
    int right = 3;
    int threshold = 2;
    int expect = 2;
    ASSERT_EQ(majorityChecker_->query(left, right, threshold), expect);
}
