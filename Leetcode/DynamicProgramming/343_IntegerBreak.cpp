//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int integerBreak(int n)
//{
//    if (n < 1)
//        return 0;
//    if (n < 3)
//        return 1;
//    if (n == 3)
//        return 2;
//
//    vector<int> dp(n + 1);
//    dp[1] = 1;
//    dp[2] = 2;
//    dp[3] = 3;
//
//    for (int i = 4; i <= n; ++i)
//    {
//        for (int j = 1; j <= i / 2; ++j)
//        {
//
//            dp[i] = max(dp[i], dp[i - j] * dp[j]);
//        }
//
//    }
//
//    return dp[n];
//}
//
//void testIntegerBreak()
//{
//    int num = 10;
//    cout << integerBreak(num) << endl;
//}
//
//int main()
//{
//    testIntegerBreak();
//    getchar();
//    return 0;
//}