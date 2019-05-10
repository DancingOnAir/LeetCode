//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//int getMaxRepetitions(string s1, int n1, string s2, int n2)
//{
//    if (s1.empty() || s2.empty() || n1 == 0 || n2 == 0)
//        return 0;
//
//    int l1 = s1.size() * n1;
//    int l2 = s2.size() * n2;
//    string newS1 = "", newS2 = "", tempS2 = "";
//
//    for (int i = 1; i <= n1; ++i)
//        newS1 += s1;
//
//    for (int i = 1; i <= n2; ++i)
//        newS2 += s2;
//
//    for (int i = 1; i * l2 <= l1; ++i)
//    {
//        vector<vector<int>> dp(l1 + 1, vector<int>(l2 * i + 1));
//        tempS2 += newS2;
//
//        for (int n = 1; n <= l2 * i; ++n)
//        {
//            for (int m = 1; m <= l1; ++m)
//            {
//                if (newS1[m] == tempS2[n])
//                {
//                    dp[m][n] = dp[m - 1][n - 1] + 1;
//                }
//                else
//                {
//                    dp[m][n] = max(dp[m - 1][n], dp[m][n - 1]);
//                }
//            }
//        }
//
//        if (dp[l1][l2 * i] < l2 * i)
//            return i - 1;
//    }
//
//    return l1 / l2;
//}
//
//int getMaxRepetitions2(string s1, int n1, string s2, int n2)
//{
//    unordered_map<int, int> repeatCount;
//    unordered_map<int, int> nextIndex;
//
//    repeatCount[0] = 0;
//    nextIndex[0] = 0;
//
//    int j = 0, cnt = 0;
//    for (int k = 1; k <= n1; ++k)
//    {
//        for (int i = 0; i < s1.size(); ++i)
//        {
//            if (s1[i] == s2[j])
//            {
//                ++j;
//                if (j == s2.size())
//                {
//                    j = 0;
//                    ++cnt;
//                }
//            }
//        }
//
//        if (nextIndex.find(j) != nextIndex.end())
//        {
//            int start = nextIndex[j];
//            int prefixCount = repeatCount[start];
//            int patternCount = (n1 - start) / (k - start) * (cnt - prefixCount);
//            int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - prefixCount;
//            return (prefixCount + patternCount + suffixCount) / n2;
//        }
//
//        repeatCount[k] = cnt;
//        nextIndex[j] = k;
//    }
//
//    return repeatCount[n1] / n2;
//}
//
//void testGetMaxRepetition()
//{
//    string s1 = "acb", s2 = "ab";
//    int n1 = 4, n2 = 2;
//
//    cout << getMaxRepetitions2(s1, n1, s2, n2) << endl;
//        
//}
//
//int main()
//{
//    testGetMaxRepetition();
//
//    getchar();
//    return 0;
//}