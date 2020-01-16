#include "pch.h"
#include "../Design/0295_FindMedianfromDataStream.h"

class MedianFinderTest: public testing::Test
{

public:
    virtual void SetUp()
    {
        medianFinder_ = new MedianFinder();
        medianFinder_->addNum(1);
        medianFinder_->addNum(2);
    }

    virtual void TearDown()
    {
        delete medianFinder_;
    }
protected:
    MedianFinder* medianFinder_;
};

TEST_F(MedianFinderTest, findMedian) {
    EXPECT_EQ(medianFinder_->findMedian(), 1.5);
}
