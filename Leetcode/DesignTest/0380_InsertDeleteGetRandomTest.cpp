#include "pch.h"
#include "../Design/0380_InsertDeleteGetRandom.h"

class RandomizedSetTest: public testing::Test
{
public:
    virtual void SetUp()
    {
        randomizedSet_ = new RandomizedSet();
        randomizedSet_->insert(1);
    }

    virtual void TearDown()
    {
        delete randomizedSet_;
    }

protected:
    RandomizedSet* randomizedSet_;
};

TEST_F(RandomizedSetTest, checkInsert)
{
    EXPECT_FALSE(randomizedSet_->insert(1));
    EXPECT_TRUE(randomizedSet_->insert(2));
}

TEST_F(RandomizedSetTest, checkRemove)
{
    EXPECT_FALSE(randomizedSet_->remove(2));
    EXPECT_TRUE(randomizedSet_->remove(1));
}

TEST_F(RandomizedSetTest, checkGetRandom)
{
    EXPECT_FALSE(randomizedSet_->getRandom() == 2);
    EXPECT_TRUE(randomizedSet_->getRandom() == 1);
}
