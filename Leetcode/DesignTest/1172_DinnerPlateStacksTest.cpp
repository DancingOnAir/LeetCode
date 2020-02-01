#include "pch.h"
#include "../Design/1172_DinnerPlateStacks.h"

class DinnerPlatesTest: public testing::Test
{
public:
    virtual void SetUp()
    {
        dinnerPlates_ = new DinnerPlates(1);
        dinnerPlates_->push(1);
        dinnerPlates_->push(2);
        dinnerPlates_->push(3);
        //dinnerPlates_->push(4);
        //dinnerPlates_->push(5);
    }

    virtual void TearDown()
    {
        delete dinnerPlates_;
    }
protected:
    DinnerPlates* dinnerPlates_;
};

TEST_F(DinnerPlatesTest, PushValue)
{
    EXPECT_EQ(dinnerPlates_->getSize(), 3);

    dinnerPlates_->push(7);
    EXPECT_EQ(dinnerPlates_->getSize(), 4);
}

TEST_F(DinnerPlatesTest, PopValue)
{
    EXPECT_EQ(dinnerPlates_->popAtStack(1), 2);
    EXPECT_EQ(dinnerPlates_->pop(), 3);
    EXPECT_EQ(dinnerPlates_->pop(), 1);

    //EXPECT_EQ(dinnerPlates_->pop(), 5);
    //EXPECT_EQ(dinnerPlates_->pop(), 4);
    //EXPECT_EQ(dinnerPlates_->pop(), 3);
    //EXPECT_EQ(dinnerPlates_->pop(), 2);
    //EXPECT_EQ(dinnerPlates_->pop(), 1);
    //EXPECT_EQ(dinnerPlates_->pop(), -1);
}

TEST_F(DinnerPlatesTest, PopAtStackValue)
{
    //EXPECT_EQ(dinnerPlates_->popAtStack(0), 2);
    //EXPECT_EQ(dinnerPlates_->popAtStack(0), 1);
    //EXPECT_EQ(dinnerPlates_->popAtStack(0), -1);
}

//TEST(DinnerPlates, CreateObjectWithCapacity)
//{
//    
//}

