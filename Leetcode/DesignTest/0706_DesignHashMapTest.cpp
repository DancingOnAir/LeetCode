#include "pch.h"
#include "../Design/0706_DesignHashMap.h"

class MyHashMapTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        myHashMap_ = new MyHashMap();
        myHashMap_->put(1, 1);
        myHashMap_->put(2, 2);
        myHashMap_->put(200, 200);
    }

    virtual void TearDown()
    {
        delete myHashMap_;
    }

protected:
    MyHashMap* myHashMap_;
};

TEST_F(MyHashMapTest, checkGet)
{
    EXPECT_EQ(myHashMap_->get(1), 1);
    EXPECT_EQ(myHashMap_->get(2), 2);
    EXPECT_EQ(myHashMap_->get(3), -1);
}

TEST_F(MyHashMapTest, checkPut)
{
    myHashMap_->put(2, 1);
    EXPECT_EQ(myHashMap_->get(2), 1);
}

TEST_F(MyHashMapTest, checkRemove)
{
    myHashMap_->remove(2);
    EXPECT_EQ(myHashMap_->get(2), -1);

    myHashMap_->remove(200);
    EXPECT_EQ(myHashMap_->get(200), -1);
}
