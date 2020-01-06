//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int minDistance(string word1, string word2)
//{
//    int l1 = word1.size();
//    int l2 = word2.size();
//
//    if (l1 == 0)
//        return l2;
//
//    if (l2 == 0)
//        return l1;
//
//    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
//    for (int i = 1; i <= l1; ++i)
//    {
//        dp[i][0] = i;
//    }
//
//    for (int j = 1; j <= l2; ++j)
//    {
//        dp[0][j] = j;
//    }
//
//    for (int i = 1; i <= l1; ++i)
//    {
//        for (int j = 1; j <= l2; ++j)
//        {
//            if (word1[i - 1] == word2[j - 1])
//                dp[i][j] = dp[i - 1][j - 1];
//            else
//                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//        }
//    }
//
//    return dp[l1][l2];
//}
//
//void testMinDistance()
//{
//    string s1 = "intention", s2 = "execution";
//    cout << minDistance(s1, s2) << endl;
//}
//
//int main()
//{
//    testMinDistance();
//
//    getchar();
//    return 0;
//}