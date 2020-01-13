#include "pch.h"
#include "../Design/0232_ImplementQueueusingStacks.h"

class MyQueueTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        myQueue_ = new MyQueue();
        myQueue_->push(1);
        myQueue_->push(2);
    }

    virtual void TearDown()
    {
        if (!myQueue_)
        {
            delete myQueue_;
            myQueue_ = nullptr;
        }
    }

protected:
    MyQueue* myQueue_;
};

TEST_F(MyQueueTest, checkPeek)
{
    EXPECT_EQ(1, myQueue_->peek());
}

TEST_F(MyQueueTest, checkPop)
{
    EXPECT_EQ(1, myQueue_->pop());
}

TEST_F(MyQueueTest, checkEmpty)
{
    EXPECT_FALSE(myQueue_->empty());
}