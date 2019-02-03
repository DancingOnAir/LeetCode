//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minCostClimbingStairs(vector<int>& cost)
//{
//    int n = cost.size();
//    if (n < 2)
//        return 0;
//
//    vector<int> dp(n + 1);
//    for (int i = 2; i <= n; ++i)
//    {
//        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//    }
//
//    return dp[n];
//}
//
//void testMinCostClimbingStairs()
//{
//    vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
//    cout << minCostClimbingStairs(cost) << endl;
//}
//
//int main()
//{
//    testMinCostClimbingStairs();
//
//    getchar();
//    return 0;
//}