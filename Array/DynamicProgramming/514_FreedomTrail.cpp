//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int findRotateSteps(string ring, string key)
//{
//    if (ring.empty() && !key.empty())
//        return 0;
//
//    int r = ring.size();
//    int k = key.size();
//    vector<vector<int>> pos(26, vector<int>());
//
//    for (int i = 0; i < r; ++i)
//        pos[ring[i] - 'a'].emplace_back(i);
//
//    vector<vector<int>> dp(r, vector<int>(k, INT_MAX));
//    int res = INT_MAX;
//    for (int i = 0; i < k; ++i)
//    {
//        int curIndex = key[i] - 'a';
//        for (int cur : pos[curIndex])
//        {
//            if (0 == i)
//            {
//                dp[cur][0] = min(cur, r - cur) + 1;
//            }
//            else
//            {
//                int preIndex = key[i - 1] - 'a';
//                for (int pre : pos[preIndex])
//                {
//                    int diff = min(abs(cur - pre), r - abs(cur - pre));
//                    dp[cur][i] = min(dp[cur][i], dp[pre][i - 1] + diff + 1);
//                }
//            }
//
//            if (k - 1 == i)
//                res = min(res, dp[cur][i]);
//        }
//    }
//    return res;
//}
//
//void testFindRotateSteps()
//{
//    string ring1 = "godding", key1 = "gd";
//    string ring2 = "abcde", key2 = "ade";
//    string key3 = "yyynnnnnnlllggg", ring3 = "nyngl";
//    cout << findRotateSteps(ring3, key3) << endl;
//}
//
//int main()
//{
//    testFindRotateSteps();
//
//    getchar();
//    return 0;
//}