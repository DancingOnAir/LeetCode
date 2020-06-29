#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> um;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                um[i - j].emplace_back(mat[i][j]);
            }
        }

        for (auto& u : um) {
            sort(u.second.rbegin(), u.second.rend());
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = um[i - j].back();
                um[i - j].pop_back();
            }
        }
        return mat;
    }
};

void printMatrix(const vector<vector<int>>& mat) {
    for (auto& row : mat) {
        for (auto& col : row) {
            cout << col << ", ";
        }
        cout << endl;
    }
}

void testDiagonalSort() {
    Solution solution;

    vector<vector<int>> mat {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    auto res = solution.diagonalSort(mat);
    printMatrix(res);
}

int main() {
    testDiagonalSort();

    return 0;
}