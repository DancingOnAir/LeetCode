#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        if (!m) {
            return vector<vector<int>>();
        }

        int n = A[0].size();
        if (!n) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = A[j][i];
            }
        }

        return res;
    }
};

void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto& col : row) {
            cout << col << ", ";
        }
        cout << endl;
    }
}

void testTranspose() {
    Solution solution;

    vector<vector<int>> matrix1 {{1,2,3},{4,5,6},{7,8,9}};
    printMatrix(matrix1);
    auto res1 = solution.transpose(matrix1);
    printMatrix(res1);

    vector<vector<int>> matrix2 {{1,2,3},{4,5,6}};
    printMatrix(matrix2);
    auto res2 = solution.transpose(matrix2);
    printMatrix(res2);
}

int main() {
    testTranspose();

    return 0;
}