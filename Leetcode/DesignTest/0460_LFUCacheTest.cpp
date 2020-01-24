#include "pch.h"
#include "../Design/0460_LFUCache.h"

class LFUCacheTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        lfuCache_ = new LFUCache(0);
        lfuCache_->put(0, 0);
    }

    void TearDown()
    {
        delete lfuCache_;
    }

protected:
    LFUCache* lfuCache_;
};

TEST_F(LFUCacheTest, checkGet)
{
    EXPECT_EQ(-1, lfuCache_->get(0));
}

