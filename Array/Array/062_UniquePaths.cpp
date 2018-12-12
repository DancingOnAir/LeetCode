//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int uniquePaths(int m, int n)
//{
//    if (1 == m || 1 == n)
//        return 1;
//
//    vector<vector<int>> matrix(n, vector<int>(m));
//    for (int i = 0; i < m; ++i)
//        matrix[0][i] = 1;
//
//    for (int i = 0; i < n; ++i)
//        matrix[i][0] = 1;
//
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 1; j < m; ++j)
//        {
//            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
//        }
//    }
//
//    return matrix[n - 1][m - 1];
//}
//
//int uniquePaths2(int m, int n)
//{
//    if (m > n)
//        uniquePaths2(n, m);
//
//    vector<int> cur(m, 1);
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 1; j < m; ++j)
//            cur[j] += cur[j - 1];
//    }
//
//    return cur[m - 1];
//}
//
//void testUniquePaths()
//{
//    int m = 7;
//    int n = 3;
//
//    cout << uniquePaths2(m, n) << endl;
//}
//
//int main()
//{
//    testUniquePaths();
//    getchar();
//}