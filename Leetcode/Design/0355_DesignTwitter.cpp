#include "0355_DesignTwitter.h"
#include <iostream>

void display(const vector<int>& nums)
{
    if (nums.empty())
        return;

    for (auto x : nums)
        cout << x << ", ";
    cout << endl;
}

void test()
{
    Twitter twitter = Twitter();

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    auto res1 = twitter.getNewsFeed(1);
    display(res1);

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    auto res2 = twitter.getNewsFeed(1);
    display(res2);

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    auto res3 = twitter.getNewsFeed(1);
    display(res3);
}

int main()
{
    test();
    getchar();
    return 0;
}