//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool existRectangle(vector<vector<char>>& matrix, int x, int y, int row, int col)
//{
//    for (int i = x; i < x + row; ++i)
//        for (int j = y; j < y + col; ++j)
//            if (matrix[i][j] != '1')
//                return false;
//    
//    //for (int i = y; i < y + col; ++i)
//    //    if (matrix[x][i] != '1' || matrix[x+row - 1][i] != '1')
//    //        return false;
//
//    return true;
//}
//
//int maximalRectangle(vector<vector<char>>& matrix)
//{
//    if (matrix.empty() || matrix[0].empty())
//        return 0;
//
//    auto m = matrix.size();
//    auto n = matrix[0].size();
//    int maxArea = INT_MIN;
//    for (int i = 0; i < m - 1; ++i)
//    {
//        for (int j = 0; j < n - 1; ++j)
//        {
//            for (int row = m - i; row > 0; --row)
//                for (int col = n - j; col > 0; --col)
//                    if (existRectangle(matrix, i, j, row, col))
//                        maxArea = max(maxArea, row * col);
//        }
//    }
//
//    return maxArea == INT_MIN? 0: maxArea;
//}
//
//
//int maximalRectangle2(vector<vector<char>>& matrix)
//{
//    if (matrix.empty() || matrix[0].empty())
//        return 0;
//
//    auto m = matrix.size();
//    auto n = matrix[0].size();
//    vector<int> heights(n, 0);
//    vector<int> lefts(n, 0);
//    vector<int> rights(n, n - 1);
//    int maxArea = 0;
//
//    for (int i = 0; i < m; ++i)
//    {
//        int curLeft = 0, curRight = n - 1;
//        for (int j = 0; j < n; ++j)
//        {
//            if ('1' == matrix[i][j])
//                ++heights[j];
//            else
//                heights[j] = 0;
//        }
//
//        for (int j = 0; j < n; ++j)
//        {
//            if ('1' == matrix[i][j])
//                lefts[j] = max(lefts[j], curLeft);
//            else
//                lefts[j] = 0, curLeft = j + 1;
//        }
//
//        for (int j = n - 1; j >= 0; --j)
//        {
//            if ('1' == matrix[i][j])
//                rights[j] = min(rights[j], curRight);
//            else
//                rights[j] = n - 1, curRight = j - 1;
//        }
//
//        for (int j = 0; j < n; ++j)
//                maxArea = max(maxArea, heights[j] * (rights[j] - lefts[j] + 1));
//    }
//    return maxArea;
//}
//
//void testMaximalRectangle()
//{
//    vector<vector<char>> matrix = { {'1', '0', '1', '0', '0'},
//                                    {'1', '0', '1', '1', '1'},
//                                    {'1', '1', '1', '1', '1'},
//                                    {'1', '0', '0', '1', '0' } };
//
//    cout << maximalRectangle2(matrix) << endl;
//}
//
//int main()
//{
//    testMaximalRectangle();
//    getchar();
//}