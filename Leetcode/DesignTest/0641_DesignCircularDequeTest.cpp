#include "pch.h"
#include "../Design/0641_DesignCircularDeque.h"

class MyCircularDequeTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        myCircularDeque_ = new MyCircularDeque(3);

    }

    virtual void TearDown()
    {
        delete myCircularDeque_;
    }

protected:
    MyCircularDeque* myCircularDeque_;
};

TEST_F(MyCircularDequeTest, IsEmpty)
{
    EXPECT_TRUE(myCircularDeque_->isEmpty());
}

TEST_F(MyCircularDequeTest, InitCapacity)
{
    EXPECT_FALSE(myCircularDeque_->isFull());
}

TEST_F(MyCircularDequeTest, InsertLast)
{
    EXPECT_TRUE(myCircularDeque_->insertLast(1));
    EXPECT_TRUE(myCircularDeque_->insertLast(2));
}

TEST_F(MyCircularDequeTest, InsertFront)
{
    EXPECT_TRUE(myCircularDeque_->insertFront(1));
}

TEST_F(MyCircularDequeTest, GetFrontValue)
{
    EXPECT_EQ(myCircularDeque_->getFront(), -1);
    myCircularDeque_->insertFront(1);
    EXPECT_EQ(myCircularDeque_->getFront(), 1);

    myCircularDeque_->insertFront(2);
    EXPECT_EQ(myCircularDeque_->getFront(), 2);
}

TEST_F(MyCircularDequeTest, GetRearValue)
{
    EXPECT_EQ(myCircularDeque_->getRear(), -1);
    myCircularDeque_->insertLast(1);
    EXPECT_EQ(myCircularDeque_->getRear(), 1);

    myCircularDeque_->insertLast(2);
    EXPECT_EQ(myCircularDeque_->getRear(), 2);
}

TEST_F(MyCircularDequeTest, DeleteFrontNode)
{
    EXPECT_FALSE(myCircularDeque_->deleteFront());

    myCircularDeque_->insertFront(1);
    myCircularDeque_->insertFront(2);
    EXPECT_TRUE(myCircularDeque_->deleteFront());
    EXPECT_EQ(myCircularDeque_->getFront(), 1);
}

TEST_F(MyCircularDequeTest, DeleteLastNode)
{
    EXPECT_FALSE(myCircularDeque_->deleteLast());

    myCircularDeque_->insertLast(1);
    myCircularDeque_->insertLast(2);
    EXPECT_TRUE(myCircularDeque_->deleteLast());
    EXPECT_EQ(myCircularDeque_->getRear(), 1);
}