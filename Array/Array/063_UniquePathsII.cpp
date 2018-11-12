#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    if (obstacleGrid.empty())
        return 0;

    size_t row = obstacleGrid.size();
    size_t col = obstacleGrid[0].size();
    vector<vector<int>> path(row + 1, vector<int>(col + 1));
    for (int i = 0; i < row; ++i)
    {
        if (obstacleGrid[i][0] != 1)
            path[i][0] = 1;
        else
            break;
    }

    for (int i = 0; i < col; ++i)
    {
        if (obstacleGrid[0][i] != 1)
            path[0][i] = 1;
        else
            break;
    }

    for (int i = 1; i < row; ++i)
    {
        for (int j = 1; j < col; ++j)
        {
            if (obstacleGrid[i][j] != 1)
                path[i][j] = path[i][j - 1] + path[i - 1][j];
        }
    }

    return path[row - 1][col - 1];
}

void testUniquePathsWithObstacles()
{
    vector<vector<int>> matrix = { { 0, 0, 0 },
                                { 0, 1, 0 },
                                { 0, 0, 0 } };
    cout << uniquePathsWithObstacles(matrix) << endl;
}

int main()
{
    testUniquePathsWithObstacles();
    system("pause");
    return 0;
}