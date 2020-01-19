#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter
{
public:
    /** Initialize your data structure here. */
    Twitter(): time_(0)
    {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        posts_[time_] = { userId, tweetId };

    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        if (!followers_.count(userId))
            return res;

        for (auto iter = posts_.begin(); iter != posts_.end(); ++iter)
        {
            if (followers_[userId].count(iter->second.first))
                res.emplace_back(iter->second.second);
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (!followers_.count(followerId))
            followers_[followerId].emplace(followerId);

        followers_[followerId].emplace(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followeeId == followerId)
            return;

        if (followers_.count(followerId))
            followers_[followerId].erase(followeeId);
    }

private:
    int time_;
    map<int, pair<int, int>, greater<int>> posts_;
    unordered_map<int, unordered_set<int>> followers_;
};