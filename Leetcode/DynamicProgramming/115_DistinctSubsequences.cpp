//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int numDistinct(string s, string t)
//{
//    int l1 = s.size();
//    int l2 = t.size();
//    if (l1 < l2)
//        return 0;
//
//    vector<vector<int>> dp(l2 + 1, vector<int>(l1 + 1));
//
//    for (int i = 0; i <= l1; ++i)
//        dp[0][i] = 1;
//
//    for (int i = 1; i <= l2; ++i)
//    {
//        for (int j = 1; j <= l1; ++j)
//        {
//            if (s[j - 1] == t[i - 1])
//            {
//                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
//            }
//            else
//                dp[i][j] = dp[i][j - 1];
//        }
//    }
//
//    return dp[l2][l1];
//}
//
//void testNumDistinct()
//{
//    string s = "babgbag";
//    string t = "bag";
//
//    cout << numDistinct(s, t) << endl;
//}
//
//int main()
//{
//    testNumDistinct();
//
//    getchar();
//    return 0;
//}