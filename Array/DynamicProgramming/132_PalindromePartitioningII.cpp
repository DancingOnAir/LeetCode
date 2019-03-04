//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minCut(string s)
//{
//    int n = s.size();
//    if (n < 2)
//        return 0;
//
//    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
//    vector<int> res(n + 1);
//
//    for (int i = 0; i <= n; ++i)
//        res[i] = i - 1;
//
//    for (int j = 0; j < n; ++j)
//    {
//        for (int i = j; i >= 0; --i)
//        {
//            if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1]))
//            {
//                isPalindrome[i][j] = true;
//                res[j + 1] = min(res[j + 1], res[i] + 1);
//            }
//        }
//    }
//
//    return res[n];
//}
//
//void testMinCut()
//{
//    string s = "aab";
//    cout << minCut(s) << endl;
//}
//
//int main()
//{
//    testMinCut();
//
//    getchar();
//    return 0;
//}