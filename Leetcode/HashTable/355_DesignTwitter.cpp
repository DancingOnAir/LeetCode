//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include <list>
//#include <set>
//#include <queue>
//
//using namespace std;
//
//class Twitter {
//public:
//    /** Initialize your data structure here. */
//    Twitter(): time(0)
//    {
//    }
//
//    /** Compose a new tweet. */
//    void postTweet(int userId, int tweetId)
//    {
//        tw[userId].emplace_back(make_pair(++time, tweetId));
//    }
//
//    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//    vector<int> getNewsFeed(int userId)
//    {
//        priority_queue<pair<int, int>> maxHeap;
//        for (auto it = tw[userId].begin(); it != tw[userId].end(); ++it)
//            maxHeap.push(*it);
//        for (auto it1 = fo[userId].begin(); it1 != fo[userId].end(); ++it1) {
//            int usr = *it1;
//            for (auto it2 = tw[usr].begin(); it2 != tw[usr].end(); ++it2)
//                maxHeap.emplace(*it2);
//        }
//        vector<int> res;
//        while (maxHeap.size() > 0) {
//            res.emplace_back(maxHeap.top().second);
//            if (res.size() == 10) break;
//            maxHeap.pop();
//        }
//        return res;
//    }
//
//    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
//    void follow(int followerId, int followeeId)
//    {
//        if (followerId != followeeId)
//            fo[followerId].emplace(followeeId);
//    }
//
//    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
//    void unfollow(int followerId, int followeeId)
//    {
//        fo[followerId].erase(followeeId);
//    }
//
//private:
//    long long time;
//    unordered_map<int, vector<pair<int, int>>> tw;
//    unordered_map<int, set<int>> fo;
//};
//
//void testTwitter()
//{
//    Twitter twitter = Twitter();
//
//    // User 1 posts a new tweet (id = 5).
//    twitter.postTweet(1, 5);
//
//    // User 1's news feed should return a list with 1 tweet id -> [5].
//    twitter.getNewsFeed(1);
//
//    // User 1 follows user 2.
//    twitter.follow(1, 2);
//
//    // User 2 posts a new tweet (id = 6).
//    twitter.postTweet(2, 6);
//
//    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
//    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//    twitter.getNewsFeed(1);
//
//    // User 1 unfollows user 2.
//    twitter.unfollow(1, 2);
//
//    // User 1's news feed should return a list with 1 tweet id -> [5],
//    // since user 1 is no longer following user 2.
//    twitter.getNewsFeed(1);
//}
//
//int main()
//{
//    testTwitter();
//
//    getchar();
//    return 0;
//}