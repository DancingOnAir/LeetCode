//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int helper(vector<vector<int>>& grid, int x, int y)
//{
//    if (!grid[x][y])
//        return 0;
//
//    int res = 4;
//    if (x > 0 && grid[x - 1][y] == 1)
//        --res;
//
//    if (x < grid.size() - 1 && grid[x + 1][y] == 1)
//        --res;
//
//    if (y > 0 && grid[x][y - 1] == 1)
//        --res;
//
//    if (y < grid[0].size() - 1 && grid[x][y + 1] == 1)
//        --res;
//
//    return res;
//}
//
//int islandPerimeter(vector<vector<int>>& grid)
//{
//    int res = 0;
//    int m = grid.size();
//    int n = grid[0].size();
//    for (int i = 0; i < m; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            res += helper(grid, i, j);
//        }
//    }
//
//    return res;
//}
//
//void testIslandPerimeter()
//{
//    vector<vector<int>> grid = { {0, 1, 0, 0},
//                                {1, 1, 1, 0},
//                                {0, 1, 0, 0},
//                                {1, 1, 0, 0} };
//    cout << islandPerimeter(grid) << endl;
//}
//
//int main()
//{
//    testIslandPerimeter();
//
//    getchar();
//    return 0;
//}