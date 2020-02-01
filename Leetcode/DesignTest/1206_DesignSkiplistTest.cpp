#include "pch.h"
#include "../Design/1206_DesignSkiplist.h"
#include <iostream>

class SkiplistTest: public testing::Test
{
public:
    virtual void SetUp()
    {
        skiplist_ = new Skiplist();
        skiplist_->add(1);
        skiplist_->add(2);
        skiplist_->add(3);
    }

    virtual void TearDown()
    {
        delete skiplist_;
    }

protected:
    Skiplist* skiplist_;
};

TEST_F(SkiplistTest, SearchValue)
{
    EXPECT_TRUE(skiplist_->search(1));
    EXPECT_TRUE(skiplist_->search(2));
    EXPECT_TRUE(skiplist_->search(3));
    EXPECT_FALSE(skiplist_->search(0));
}

TEST_F(SkiplistTest, AddValue)
{
    skiplist_->add(4);
    EXPECT_TRUE(skiplist_->search(4));
}

TEST_F(SkiplistTest, EraseValue)
{
    EXPECT_TRUE(skiplist_->erase(1));
    EXPECT_FALSE(skiplist_->erase(0));

    EXPECT_FALSE(skiplist_->search(1));
}
