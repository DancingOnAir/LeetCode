#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = (i * n + j + k) % (m * n);
                res[index / n][index % n] = grid[i][j];
            }
        }

        return res;
    }

    vector<vector<int>> shiftGrid1(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k %= m*n;
        if (!k)
            return grid;

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int r = (i + (j + k) / n) % m;
                int c = (j + k) % n;
                res[r][c] = grid[i][j];
            }
        }

        return res;
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (auto& r : matrix) {
        for (auto& c : r) {
            cout << c << ", ";
        }
        cout << endl;
    }

    cout << endl;
}

void testShiftGrid() {
    Solution solution;

    vector<vector<int>> grid1 = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int k1 = 1;
    auto res1 = solution.shiftGrid(grid1, k1);
    printMatrix(res1);

    vector<vector<int>> grid2 = {{3, 8, 1, 9},{19, 7, 2, 5},{4, 6, 11, 10},{12, 0, 21, 13}};
    int k2 = 4;
    auto res2 = solution.shiftGrid(grid2, k2);
    printMatrix(res2);

    vector<vector<int>> grid3 = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int k3 = 9;
    auto res3 = solution.shiftGrid(grid3, k3);
    printMatrix(res3);

    vector<vector<int>> grid4 = {{1}, {2}, {3}, {4}, {7}, {6}, {5}};
    int k4 = 23;
    auto res4 = solution.shiftGrid(grid4, k4);
    printMatrix(res4);
}

int main() {
    testShiftGrid();

    return 0;
}