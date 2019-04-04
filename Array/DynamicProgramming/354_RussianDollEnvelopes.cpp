//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int maxEnvelopes(vector<pair<int, int>>& envelopes)
//{
//    if (envelopes.empty())
//        return 0;
//
//    sort(envelopes.begin(), envelopes.end());
//
//    int res = 0;
//    int n = envelopes.size();
//
//    vector<int> dp(n);
//    for (int i = 0; i < n; ++i)
//    {
//        dp[i] = 1;
//        for (int j = 0; j < i; ++j)
//        {
//            if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
//            {
//                dp[i] = max(dp[i], dp[j] + 1);
//            }
//        }
//
//        res = max(res, dp[i]);
//    }
//
//    return res;
//}
//
//int maxEnvelopes2(vector<pair<int, int>>& envelopes)
//{
//    if (envelopes.empty())
//        return 0;
//
//    sort(envelopes.begin(), envelopes.end(), [](pair<int, int> lhs, pair<int, int> rhs) 
//    {
//        return (lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second > rhs.second);
//    });
//
//    vector<int> res;
//    for (auto& envelop : envelopes)
//    {
//        auto iter = lower_bound(res.begin(), res.end(), envelop.second);
//        if (iter == res.end())
//            res.emplace_back(envelop.second);
//        else if (*iter > envelop.second)
//            *iter = envelop.second;
//    }
//
//    return res.size();
//}
//
//void testMaxEnvelopes()
//{
//    vector<pair<int, int>> envelopes = { {5,4},{6,4},{6,7},{2,3} };
//    cout << maxEnvelopes2(envelopes) << endl;
//}
//
//int main()
//{
//    testMaxEnvelopes();
//    getchar();
//    return 0;
//}