//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//pair<int, int> calculateZerosAndOnes(const string& str)
//{
//    if (str.empty())
//        return make_pair(0, 0);
//
//    int zeroCount = 0, oneCount = 0;
//    for (char c : str)
//    {
//        if ('0' == c)
//            ++zeroCount;
//        else
//            ++oneCount;
//    }
//
//    return make_pair(zeroCount, oneCount);
//}
//
//int findMaxForm(vector<string>& strs, int m, int n)
//{
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//    int zeroCount = 0, oneCount = 0;
//
//    for (int i = 0; i < strs.size(); ++i)
//    {
//        auto temp = calculateZerosAndOnes(strs[i]);
//        zeroCount = temp.first;
//        oneCount = temp.second;
//
//        for (int j = m; j >= zeroCount; --j)
//        {
//            for (int k = n; k >= oneCount; --k)
//            {
//                dp[j][k] = max(dp[j][k], dp[j - zeroCount][k - oneCount] + 1);
//            }
//        }
//    }
//
//    return dp[m][n];
//}
//
//void testFindMaxForm()
//{
//    vector<string> strs = { "10", "0001", "111001", "1", "0" };
//    int m = 5, n = 3;
//
//    cout << findMaxForm(strs, m, n) << endl;
//}
//
//int main()
//{
//    testFindMaxForm();
//
//    getchar();
//    return 0;
//}