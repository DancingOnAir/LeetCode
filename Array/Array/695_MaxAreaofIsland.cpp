#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateAreaOfIsland(vector<vector<int>>& grid, int x, int y)
{
    int m = grid.size();
    int n = grid[0].size();
    int area = 1;

    grid[x][y] = -1;

    vector<int> offset({ -1, 0, 1, 0, -1 });
    for (int i = 0; i < offset.size() - 1; ++i)
    {
        int r = x + offset[i], c = y + offset[i + 1];
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
            area += calculateAreaOfIsland(grid, r, c);
    }

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;

    int res = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 1)
                res = max(res, calculateAreaOfIsland(grid, i, j));
        }
    }

    return res;
}

void testMaxAreaOfIsland()
{
    vector<vector<int>> grid = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };

    cout << maxAreaOfIsland(grid) << endl;
}

int main()
{
    testMaxAreaOfIsland();

    getchar();
    return 0;
}