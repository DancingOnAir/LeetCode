#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        posts.emplace_back(make_pair(userId, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;

        for (auto iter = posts.rbegin(); iter != posts.rend(); ++iter)
        {
            if (iter->first == userId || find(follows[userId].begin(), follows[userId].end(), iter->first) != follows[userId].end())
                res.emplace_back(iter->second);

            if (res.size() == 10)
                return res;
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        follows[followerId].emplace_back(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].remove(followeeId);
    }

private:
    //unordered_map<int, vector<int>> posts;
    vector<pair<int, int>> posts;
    unordered_map<int, list<int>> follows;
};

void testTwitter()
{
    Twitter twitter = Twitter();

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    twitter.getNewsFeed(1);

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.getNewsFeed(1);

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    twitter.getNewsFeed(1);
}

int main()
{
    testTwitter();

    getchar();
    return 0;
}