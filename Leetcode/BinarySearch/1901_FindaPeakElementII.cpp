#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = mat[0].size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int maxRow = 0;
            for (int i = 0; i < mat.size(); ++i) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool leftIsBigger = (mid - 1 >= left) && (mat[maxRow][mid - 1] > mat[maxRow][mid]);
            bool rightIsBigger = (mid + 1 <= right) && (mat[maxRow][mid + 1] > mat[maxRow][mid]);
            if (!leftIsBigger && !rightIsBigger) {
                return vector<int> {maxRow, mid};
            }
            else if (leftIsBigger) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return vector<int>();
    }
};

void testFindPeakGrid() {
    Solution solution;
    vector<vector<int>> mat1 {{1,4},{3,2}};
    auto res1 = solution.findPeakGrid(mat1);
    cout << res1[0] << ", " << res1[1] << endl;

    vector<vector<int>> mat2 {{10,20,15},{21,30,14},{7,16,32}};
    auto res2 = solution.findPeakGrid(mat2);
    cout << res2[0] << ", " << res2[1] << endl;
}

int main() {
    testFindPeakGrid();
    return 0;
}