#include "pch.h"
#include "../Design/0355_DesignTwitter.h"

class TwitterTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        twitter_ = new Twitter();
        twitter_->postTweet(1, 5);
        //twitter_->follow(1, 2);
        //twitter_->postTweet(2, 6);
    }

    virtual void TearDown()
    {
        delete twitter_;
    }

protected:
    Twitter* twitter_;
};

TEST_F(TwitterTest, checkPostTweet)
{
    //EXPECT_EQ(twitter_->getNewsFeed(1)[0], 6);
    EXPECT_EQ(twitter_->getNewsFeed(1)[0], 5);
}