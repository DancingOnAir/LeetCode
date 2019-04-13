//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int getMoneyAmount(int n)
//{
//    if (n < 1)
//        return 0;
//
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//
//    for (int j = 2; j <= n; ++j)
//    {
//        for (int i = j - 1; i > 0; --i)
//        {
//            dp[i][j] = INT_MAX;
//            for (int k = i + 1; k < j; ++k)
//            {
//                int temp = k + max(dp[i][k - 1], dp[k + 1][j]);
//                dp[i][j] = min(dp[i][j], temp);
//            }
//
//            if (i + 1 == j)
//                dp[i][j] = i;
//        }
//    }
//
//    return dp[1][n];
//}
//
//void testGetMoneyAmount()
//{
//    int n = 10;
//    cout << getMoneyAmount(n) << endl;
//}
//
//int main()
//{
//    testGetMoneyAmount();
//
//    getchar();
//    return 0;
//}
