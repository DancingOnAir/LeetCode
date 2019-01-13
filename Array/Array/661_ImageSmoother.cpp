#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, int row, int col)
{
    if (x >= 0 && x < row && y >= 0 && y < col)
        return true;

    return false;
}

vector<vector<int>> imageSmoother(vector<vector<int>>& M)
{
    int m = M.size();
    if (0 == m)
        return{ {} };

    int n = M[0].size();
    if (0 == n)
        return{ {} };

    int count = 0, sum = 0;
    vector<vector<int>> res(m, vector<int>(n));
    vector<int> offset = { -1, 0, 1 };

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum = 0;
            count = 0;

            for (int r : offset)
            {
                for (int c : offset)
                {
                    if (isValid(i + r, j + c, m, n))
                    {
                        sum += M[i + r][j + c];
                        ++count;
                    }

                }
            }

            res[i][j] = sum / count;
        }
    }

    return res;
}

void testImageSmoother()
{
    vector<vector<int>> matrix = { {1, 1, 1},
                                {1, 0, 1},
                                {1, 1, 1} };

    auto res = imageSmoother(matrix);

    for (auto& row : res)
    {
        for (auto& col : row)
            cout << col << ", ";
        cout << endl;
    }
}

int main()
{
    testImageSmoother();

    getchar();
    return 0;
}