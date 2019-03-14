//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int calculateMinimumHP(vector<vector<int>>& dungeon)
//{
//    int m = dungeon.size();
//    if (0 == m)
//        return 0;
//
//    int n = dungeon[0].size();
//    if (0 == n)
//        return 0;
//
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
//    dp[m][n - 1] = 1;
//    dp[m - 1][n] = 1;
//    for (int i = m - 1; i >= 0; --i)
//    {
//        for (int j = n - 1; j >= 0; --j)
//        {
//            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
//        }
//    }
//
//    return dp[0][0];
//}
//
//void testCalculateMinimumHP()
//{
//    vector<vector<int>> dungeon{ {-2, -3, 3}, {-5, -10, 1}, {10, 30, -5} };
//
//    cout << calculateMinimumHP(dungeon) << endl;
//}
//
//int main()
//{
//    testCalculateMinimumHP();
//
//    getchar();
//    return 0;
//}