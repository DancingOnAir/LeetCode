//#include <iostream>
//#include <vector>
//
//#define min(a, b) ((a) < (b)? (a):(b))
//#define max(a, b) ((a) > (b)? (a):(b))
//
//using namespace std;
//
//int maximalSquare(vector<vector<char>>& matrix)
//{
//    int m = matrix.size();
//    if (0 == m)
//        return 0;
//
//    int n = matrix[0].size();
//    if (0 == n)
//        return 0;
//
//    int size = INT_MIN;
//    vector<vector<int>> dp(m, vector<int>(n));
//    for (int i = 0; i < m; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            if (!i || !j || matrix[i][j] == '0')
//            {
//                dp[i][j] = matrix[i][j] - '0';
//            }
//            else
//            {
//                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
//            }
//
//            size = max(size, dp[i][j]);
//        }
//    }
//    return size * size;
//}
//
//void testMaximalSquare()
//{
//    vector<vector<char>> matrix = { { '1', '0', '1', '0', '0' },
//                                    { '1', '0', '1', '1', '1' },
//                                    { '1', '1', '1', '1', '1' },
//                                    { '1', '0', '0', '1', '0' } };
//
//    cout << (maximalSquare(matrix) == 4? "true":"false") << endl;
//}
//
//int main()
//{
//    testMaximalSquare();
//
//    getchar();
//    return 0;
//}