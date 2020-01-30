#include "pch.h"
#include "../Design/0622_DesignCircularQueue.h"

class MyCircularQueueTest: public testing::Test
{
public:
    virtual void SetUp()
    {
        myCircularQueue_ = new MyCircularQueue(3);
    }

    virtual void TearDown()
    {
        delete myCircularQueue_;
    }

protected:
    MyCircularQueue* myCircularQueue_;
};

TEST_F(MyCircularQueueTest, IsEmpty)
{
    EXPECT_TRUE(myCircularQueue_->isEmpty());
}

TEST_F(MyCircularQueueTest, IsFull)
{
    EXPECT_FALSE(myCircularQueue_->isFull());
}

TEST_F(MyCircularQueueTest, PushBackValueInQueue)
{
    EXPECT_TRUE(myCircularQueue_->enQueue(1));
}

TEST_F(MyCircularQueueTest, PopFrontValueOutQueue)
{
    EXPECT_FALSE(myCircularQueue_->deQueue());
}

TEST_F(MyCircularQueueTest, GetFrontValue)
{
    EXPECT_EQ(myCircularQueue_->Front(), -1);

    EXPECT_TRUE(myCircularQueue_->enQueue(1));
    EXPECT_EQ(myCircularQueue_->Front(), 1);

    EXPECT_TRUE(myCircularQueue_->enQueue(2));
    EXPECT_EQ(myCircularQueue_->Front(), 1);
}

TEST_F(MyCircularQueueTest, GetRearValue)
{
    EXPECT_EQ(myCircularQueue_->Rear(), -1);

    EXPECT_TRUE(myCircularQueue_->enQueue(1));
    EXPECT_EQ(myCircularQueue_->Rear(), 1);

    EXPECT_TRUE(myCircularQueue_->enQueue(2));
    EXPECT_EQ(myCircularQueue_->Rear(), 2);
}