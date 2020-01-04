//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minPathSum(vector<vector<int>>& grid)
//{
//    int m = grid.size();
//    int n = grid[0].size();
//
//    vector<int> dp(n);
//    for (int i = 0; i < n; ++i)
//    {
//        if (0 == i)
//            dp[0] = grid[0][0];
//        else
//            dp[i] = grid[0][i] + dp[i - 1];
//    }
//
//    for (int i = 1; i < m; ++i)
//    {
//        dp[0] += grid[i][0];
//        for (int j = 1; j < n; ++j)
//        {
//            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
//        }
//    }
//
//    return dp[n - 1];
//}
//
//void testMinPathSum()
//{
//    vector<vector<int>> grid1 = {{1, 3, 1},
//                                {1, 5, 1},
//                                {4, 2, 1}};
//
//    cout << minPathSum(grid1) << endl;
//}
//
//int main()
//{
//    testMinPathSum();
//
//    getchar();
//    return 0;
//}