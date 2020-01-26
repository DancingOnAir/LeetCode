#include "pch.h"
#include "../Design/0705_DesignHashSet.h"

class MyHashSetTest: public testing::Test
{
public:
    virtual void SetUp()
    {
        myHashSet_ = new MyHashSet();
        myHashSet_->add(1);
        myHashSet_->add(2);
    }

    virtual void TearDown()
    {
        delete myHashSet_;
    }

protected:
    MyHashSet* myHashSet_;
};

TEST_F(MyHashSetTest, checkContains)
{
    EXPECT_TRUE(myHashSet_->contains(1));
    EXPECT_FALSE(myHashSet_->contains(3));
}

TEST_F(MyHashSetTest, checkAdd)
{
    myHashSet_->add(3);
    EXPECT_TRUE(myHashSet_->contains(3));
}

TEST_F(MyHashSetTest, checkRemove)
{
    myHashSet_->remove(2);
    EXPECT_FALSE(myHashSet_->contains(2));
}