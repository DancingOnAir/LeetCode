//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool isMagicSquare(vector<vector<int>>& grid, int x, int y)
//{
//    string str = "" + grid[x - 1][y - 1] + grid[x - 1][y] + grid[x - 1][y + 1] + grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 1][y] + grid[x + 1][y - 1] + grid[x][y - 1];
//    return string("4381672943816729").find(str) != string::npos || string("9276183492761834").find(str) != string::npos;
//}
//
//int numMagicSquaresInside(vector<vector<int>>& grid)
//{
//    int m = grid.size();
//    if (m < 3)
//        return 0;
//
//    int n = grid[0].size();
//    if (n < 3)
//        return 0;
//
//    int res = 0;
//    for (int i = 1; i < m - 1; ++i)
//    {
//        for (int j = 1; j < n - 1; ++j)
//        {
//            if (grid[i][j] == 5)
//            {
//                res += (isMagicSquare(grid, i, j)?1:0);
//            }
//        }
//    }
//
//    return res;
//}
//
//void testNumMagicSquaresInside()
//{
//    vector<vector<int>> grid = { {4, 3, 8, 4},
//                                {9, 5, 1, 9},
//                                {2, 7, 6, 2} };
//
//    cout << numMagicSquaresInside(grid) << endl;
//}
//
//int main()
//{
//    testNumMagicSquaresInside();
//
//    getchar();
//    return 0;
//}