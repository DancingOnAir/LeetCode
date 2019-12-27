//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool isInterleave(string s1, string s2, string s3)
//{
//    int l1 = s1.size();
//    int l2 = s2.size();
//    int l3 = s3.size();
//
//    if (l3 != l1 + l2)
//        return false;
//
//    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
//
//    for (int i = 0; i <= l1; ++i)
//    {
//        for (int j = 0; j <= l2; ++j)
//        {
//            if (i == 0 && j == 0)
//            {
//                dp[i][j] = true;
//            }
//            else if (i == 0)
//            {
//                dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
//            }
//            else if (j == 0)
//            {
//                dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
//            }
//            else
//            {
//                dp[i][j] = (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])) || (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
//            }
//        }
//    }
//
//    return dp[l1][l2];
//}
//
//void testIsInterleave()
//{
//    string s1 = "aabcc";
//    string s2 = "dbbca";
//    string s3 = "aadbbcbcac";
//    string s4 = "aadbbbaccc";
//
//    cout << (isInterleave(s1, s2, s3) ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testIsInterleave();
//
//    getchar();
//    return 0;
//}