//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//string longestPalindrome2(string s)
//{
//    int n = s.size();
//    if (n < 2)
//        return s;
//
//    vector<vector<bool>> dp(n, vector<bool>(n, false));
//    int maxLen = 1;
//    int maxStart = 0;
//
//    for (int i = 0; i < n; ++i)
//        dp[i][i] = true;
//
//    for (int i = 0; i < n - 1; ++i)
//    {
//        if (s[i] == s[i + 1])
//        {
//            dp[i][i + 1] = true;
//            maxLen = 2;
//            maxStart = i;
//        }
//    }
//
//    for (int len = 3; len <= n; ++len)
//    {
//        for (int i = 0; i + len - 1 < n; ++i)
//        {
//            int j = i + len - 1;
//            if (s[i] == s[j] && dp[i + 1][j - 1])
//            {
//                dp[i][j] = true;
//                maxLen = len;
//                maxStart = i;
//            }
//        }
//    }
//
//    return s.substr(maxStart, maxLen);
//}
//
//string longestPalindrome(string s)
//{
//    int n = s.size();
//    if (n < 2)
//        return s;
//
//    int maxLen = 0;
//    int maxStart = 0;
//
//    for (int i = 0; i < n;)
//    {
//        if (n - i < maxLen / 2)
//            break;
//
//        int j = i, k = i;
//        while (k < n - 1 && s[k + 1] == s[k])
//            ++k;
//
//        i = k + 1;
//        while (k < n - 1 && j > 0 && s[k + 1] == s[j - 1])
//        {
//            ++k;
//            --j;
//        }
//
//        int newLen = k - j + 1;
//        if (newLen > maxLen)
//        {
//            maxLen = newLen;
//            maxStart = j;
//        }
//
//    }
//
//    return s.substr(maxStart, maxLen);
//}
//
//void testLongestPalindrome()
//{
//    string s1 = "babad";
//    cout << longestPalindrome(s1) << endl;
//
//    string s2 = "cbbd";
//    cout << longestPalindrome(s2) << endl;
//}
//
//int main()
//{
//    testLongestPalindrome();
//
//    getchar();
//    return 0;
//}