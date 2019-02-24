//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int climbStairs(int n)
//{
//    if (n <= 0)
//        return 0;
//    if (n == 1)
//        return 1;
//
//    vector<int> dp(n + 1);
//    dp[1] = 1;
//    dp[2] = 2;
//
//    for (int i = 3; i <= n; ++i)
//        dp[i] = dp[i - 1] + dp[i - 2];
//
//    return dp[n];
//}
//
//void testClimbStairs()
//{
//    cout << climbStairs(0) << endl;
//    cout << climbStairs(1) << endl;
//    cout << climbStairs(2) << endl;
//    cout << climbStairs(3) << endl;
//}
//
//int main()
//{
//    testClimbStairs();
//
//    getchar();
//    return 0;
//}