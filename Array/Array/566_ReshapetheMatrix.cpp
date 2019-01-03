#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    size_t m = nums.size();
    size_t n = nums[0].size();

    if (m * n != r * c)
        return nums;

    vector<vector<int>> res(r, vector<int>(c));
    int x = 0, y = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            x = (i * n + j) / c;
            y = (i * n + j) % c;
            res[x][y] = nums[i][j];
        }
    }

    return res;
}

vector<vector<int>> matrixReshape2(vector<vector<int>>& nums, int r, int c)
{
    size_t m = nums.size();
    size_t n = nums[0].size();

    if (m * n != r * c)
        return nums;

    vector<vector<int>> res(r, vector<int>(c));
    int x = 0, y = 0;
    int i1 = 0, j1 = 0;
    int count = n;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            res[i][j] = nums[i1][j1];
            ++j1;

            if (j1 >= count)
            {
                j1 = 0;
                ++i1;
            }
        }
    }

    return res;
}

void testMatrixReshape()
{
    vector<vector<int>> nums = {{1, 2},
                                {3, 4}};
    int r = 1, c = 4;
    auto res = matrixReshape2(nums, r, c);

    for (auto& row : res)
    {
        for (auto& col : row)
            cout << col << ", ";
        cout << endl;
    }
}

int main()
{
    testMatrixReshape();
    getchar();
    return 0;
}