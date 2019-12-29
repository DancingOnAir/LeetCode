//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//bool isMatch(string s, string p)
//{
//    int m = s.size();
//    int n = p.size();
//    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
//    dp[0][0] = true;
//    for (int i = 0; i <= m; ++i)
//    {
//        for (int j = 1; j <= n; ++j)
//        {
//            if ('*' != p[j - 1])
//            {
//                dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
//            }
//            else
//            {
//                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2]));
//            }
//        }
//    }
//
//    return dp[m][n];
//}
//
//void testIsMatch()
//{
//    string s1 = "";
//    string p1 = ".*";
//    cout << (isMatch(s1, p1) ? "True" : "False") << endl;
//
//    string s2 = "aa";
//    string p2 = "a*";
//    cout << (isMatch(s2, p2) ? "True" : "False") << endl;
//
//    string s3 = "aab";
//    string p3 = "c*a*b";
//    cout << (isMatch(s3, p3) ? "True" : "False") << endl;
//
//    string s4 = "mississippi";
//    string p4 = "mis*is*ip*.";
//    cout << (isMatch(s4, p4) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testIsMatch();
//
//    getchar();
//    return 0;
//}