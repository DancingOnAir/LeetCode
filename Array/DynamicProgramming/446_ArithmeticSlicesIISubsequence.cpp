//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//int numberOfArithmeticSlices(vector<int>& A)
//{
//    int n = A.size();
//    int res = 0;
//
//    if (n < 3)
//        return res;
//
//    vector<unordered_map<int, int>> dp(n);
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            long long diff = A[i] -A[j];
//            if (diff < INT_MIN || diff > INT_MAX)
//                continue;
//
//            int d = (int)diff;
//            ++dp[i][d];
//
//            if (dp[j].find(d) != dp[j].end())
//            {
//                dp[i][d] += dp[j][d];
//                res += dp[j][d];
//            }
//        }
//    }
//
//    return res;
//}
//
//void testNumberOfArithmeticSlices()
//{
//    vector<int> A = { 2, 4, 6, 8, 10 };
//    vector<int> B = { 0, 2000000000, -294967296 };
//    vector<int> C = { 0, 1, 2, 3 };
//    cout << numberOfArithmeticSlices(C) << endl;
//}
//
//int main()
//{
//    testNumberOfArithmeticSlices();
//
//    getchar();
//    return 0;
//}