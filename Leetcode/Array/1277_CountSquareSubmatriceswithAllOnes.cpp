#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); res += matrix[i][j++]) {
                if (i && j && matrix[i][j]) {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                }
            }
        }

        return res;
    }

    int countSquares1(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int res = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int len = 0;
                
                while ((r + len < m) && (c + len < n)) {
                    bool isSquare = true;
                    for (int i = 0; i < len + 1; ++i) {
                        if (!matrix[r + i][c + len]|| !matrix[r + len][c + i]) {
                            isSquare = false;
                            break;
                        }
                    }
                    
                    if (!isSquare) {
                        break;
                    }

                    ++len;
                    ++res;
                }
            }
        }

        return res;
    }
};

void testCountSquares() {
    Solution solution;

    vector<vector<int>> matrix1 ={{0,1,1,1},
                                {1,1,1,1},
                                {0,1,1,1}};
    cout << solution.countSquares(matrix1) << endl;

    vector<vector<int>> matrix2 ={{1,0,1},
                                {1,1,0},
                                {1,1,0}};
    cout << solution.countSquares(matrix2) << endl;
}

int main() {
    testCountSquares();

    return 0;
}

