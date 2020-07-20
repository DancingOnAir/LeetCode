#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

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

    // vector<vector<int>> matrix3 ={{0,1,1,1},
    //                             {1,1,1,1},
    //                             {0,1,1,1}};
    // cout << solution.countSquares(matrix3) << endl;
}

int main() {
    testCountSquares();

    return 0;
}

