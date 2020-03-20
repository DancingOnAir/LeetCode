#include "pch.h"
#include "../SegmentTree/0732_MyCalendarIII.h"

using namespace testing;
class AMyCalendarThree : public Test
{
public:
    virtual void SetUp()
    {
        myCalendarThree_ = new MyCalendarThree();
    }

    virtual void TearDown()
    {
        delete myCalendarThree_;
    }

protected:
    MyCalendarThree* myCalendarThree_;
};

TEST_F(AMyCalendarThree, AnswerDisjointEvents)
{
    EXPECT_EQ(myCalendarThree_->book(10, 20), 1);
    ASSERT_EQ(myCalendarThree_->book(50, 60), 1);
}

TEST_F(AMyCalendarThree, AnswerInteractedEvents)
{
    myCalendarThree_->book(10, 20);
    ASSERT_EQ(myCalendarThree_->book(10, 40), 2);
}

TEST_F(AMyCalendarThree, AnswerThreeBookingEvents)
{
    myCalendarThree_->book(10, 20);
    myCalendarThree_->book(10, 40);
    EXPECT_EQ(myCalendarThree_->book(5, 15), 3);
    EXPECT_EQ(myCalendarThree_->book(5, 10), 3);
    ASSERT_EQ(myCalendarThree_->book(25, 55), 3);
}