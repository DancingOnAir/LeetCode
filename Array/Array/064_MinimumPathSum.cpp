//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int minPathSum(vector<vector<int>>& grid)
//{
//    if (grid.empty())
//        return 0;
//
//    int row = grid.size();
//    int col = grid[0].size();
//    vector<vector<int>> path(row + 1, vector<int>(col + 1));
//    int sum = 0;
//    for (int i = 0; i < row; ++i)
//    {
//        sum += grid[i][0];
//        path[i][0] = sum;
//
//    }
//
//    sum = 0;
//    for (int i = 0; i < col; ++i)
//    {
//        sum += grid[0][i];
//        path[0][i] = sum;
//    }
//
//    for (int i = 1; i < row; ++i)
//    {
//        for (int j = 1; j < col; ++j)
//        {
//            path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j];
//        }
//    }
//
//    return path[row - 1][col - 1];
//}
//
//void testMinPathSum()
//{
//    vector<vector<int>> matrix = { { 1, 3, 1 },
//                                { 1, 5, 1 },
//                                { 4, 2, 1 } };
//    cout << minPathSum(matrix) << endl;
//}
//
//int main()
//{
//    testMinPathSum();
//    system("pause");
//    return 0;
//}