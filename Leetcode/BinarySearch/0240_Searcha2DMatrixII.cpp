#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int r = 0, c = matrix[0].size() - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] < target) {
                ++r;
            }
            else if (matrix[r][c] > target) {
                --c;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

void testSearchMatrix() {
    Solution solution;
    vector<vector<int>> matrix {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << solution.searchMatrix(matrix, 5) << endl;
    cout << solution.searchMatrix(matrix, 20) << endl;
}

int main() {
    testSearchMatrix();
    return 0;
}