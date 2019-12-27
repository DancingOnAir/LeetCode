//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int numSquares(int n)
//{
//    if (n < 1)
//        return 0;
//
//    vector<int> dp(n + 1, INT_MAX);
//    dp[0] = 0;
//    
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j * j <= i; ++j)
//        {
//            dp[i] = min(dp[i], dp[i - j * j] + 1);
//        }
//    }
//
//    return dp.back();
//}
//
//void testNumSquares()
//{
//    int n1 = 12, n2 = 13;
//
//    cout << numSquares(n1) << endl;
//    cout << numSquares(n2) << endl;
//}
//
//int main()
//{
//    testNumSquares();
//
//    getchar();
//    return 0;
//}