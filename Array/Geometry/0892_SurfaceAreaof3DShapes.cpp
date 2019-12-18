#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int surfaceArea(vector<vector<int>>& grid)
{
    int m = grid.size();
    if (0 == m)
        return 0;
    int n = grid[0].size();
    if (0 == n)
        return 0;

    int res = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j])
                res += grid[i][j] * 4 + 2;
            if (i)
                res -= min(grid[i - 1][j], grid[i][j]) * 2;
            if (j)
                res -= min(grid[i][j - 1], grid[i][j]) * 2;
        }
    }

    return res;
}

void testSurfaceArea()
{
    vector<vector<int>> grid1 = { {2} };
    cout << surfaceArea(grid1) << endl;

    vector<vector<int>> grid2 = { {1, 2}, {3, 4} };
    cout << surfaceArea(grid2) << endl;

    vector<vector<int>> grid3 = { {1, 0}, {0, 2} };
    cout << surfaceArea(grid3) << endl;

    vector<vector<int>> grid4 = { {2, 2, 2},{2, 1, 2},{2, 2, 2} };
    cout << surfaceArea(grid4) << endl;
}

int main()
{
    testSurfaceArea();

    getchar();
    return 0;
}