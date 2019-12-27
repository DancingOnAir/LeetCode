//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void backtracking(int m, int n, int N, int i, int j, int& res)
//{
//    if (N < 0)
//    {
//        return;
//    }
//
//    if (i < 0 || i >= m || j < 0 || j >= n)
//    {
//        ++res;
//        return;
//    }
//
//    backtracking(m, n, N - 1, i + 1, j, res);
//    backtracking(m, n, N - 1, i - 1, j, res);
//    backtracking(m, n, N - 1, i, j + 1, res);
//    backtracking(m, n, N - 1, i, j - 1, res);
//}
//
//int findPaths1(int m, int n, int N, int i, int j)
//{
//    if (m < 1 || n < 1 || N < 1 || i < 0 || j < 0)
//        return 0;
//
//    int res = 0;
//    backtracking(m, n, N, i, j, res);
//
//    return res;
//}
//
//int findPaths2(int m, int n, int N, int i, int j)
//{
//    vector<vector<vector<unsigned int>>> dp(N + 1, vector<vector<unsigned int>>(m, vector<unsigned int>(n)));
//    for (auto Ni = 1; Ni <= N; ++Ni)
//    {
//        for (auto mi = 0; mi < m; ++mi)
//        {
//            for (auto ni = 0; ni < n; ++ni)
//            {
//                dp[Ni][mi][ni] = ((mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + (mi == m - 1 ? 1 : dp[Ni - 1][mi + 1][ni])
//                    + (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1])) % (1000000007);
//            }
//        }
//    }
//
//    return dp[N][i][j];
//}
//
//void testFindPaths()
//{
//    cout << findPaths2(2, 2, 2, 0, 0) << endl;
//    cout << findPaths2(1, 3, 3, 0, 1) << endl;
//}
//
//int main()
//{
//    testFindPaths();
//    getchar();
//    return 0;
//}