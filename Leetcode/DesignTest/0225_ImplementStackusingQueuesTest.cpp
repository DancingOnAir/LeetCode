#include "pch.h"
#include "../Design/0225_ImplementStackusingQueues.h"

class MyStackTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        myStack_ = new MyStack();
        myStack_->push(1);
        myStack_->push(2);
    }

    virtual void TearDown()
    {
        if (!myStack_)
        {
            delete myStack_;
            myStack_ = nullptr;
        }
    }

protected:
    MyStack* myStack_;
};

TEST_F(MyStackTest, checkTop)
{
    EXPECT_EQ(2, myStack_->top());
}

TEST_F(MyStackTest, checkPop)
{
    EXPECT_EQ(2, myStack_->pop());
    EXPECT_EQ(1, myStack_->top());
}

TEST_F(MyStackTest, checkEmpty)
{
    ASSERT_FALSE(myStack_->empty());
}
