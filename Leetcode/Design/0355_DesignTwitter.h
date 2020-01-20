#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter1
{
public:
    /** Initialize your data structure here. */
    Twitter1(): time_(0)
    {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        posts_[time_++] = { userId, tweetId };

        if (!followers_.count(userId))
            followers_[userId].emplace(userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        if (!followers_.count(userId))
            return res;

        for (auto iter = posts_.begin(); iter != posts_.end() && res.size() < 10; ++iter)
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

class Twitter
{
public:
    /** Initialize your data structure here. */
    Twitter() : timestamp_(0)
    {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        userPost_[userId].push_back({ timestamp_++, tweetId });

        //if (!userFollower_.count(userId))
        //    followers_[userId].emplace(userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> maxHeap;
        for (auto iter = userPost_[userId].begin(); iter != userPost_[userId].end(); ++iter)
        {
            maxHeap.emplace(*iter);
        }

        for (auto iter1 = userFollower_[userId].begin(); iter1 != userFollower_[userId].end(); ++iter1)
        {
            for (auto iter2 = userPost_[*iter1].begin(); iter2 != userPost_[*iter1].end(); ++iter2)
            {
                maxHeap.emplace(*iter2);
            }
        }
        vector<int> res;
        while (!maxHeap.empty())
        {
            res.emplace_back(maxHeap.top().second);
            maxHeap.pop();
            if (res.size() >= 10)
                break;
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        userFollower_[followerId].emplace(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followeeId == followerId)
            return;

        if (userFollower_.count(followerId))
            userFollower_[followerId].erase(followeeId);
    }

private:
    int timestamp_;
    unordered_map<int, vector<pair<int, int>>> userPost_;
    unordered_map<int, unordered_set<int>> userFollower_;
};
