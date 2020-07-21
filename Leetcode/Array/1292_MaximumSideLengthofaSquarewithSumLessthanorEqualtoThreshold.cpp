#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> presum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                presum[i][j] = mat[i - 1][j - 1] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
            }
        }

        int res = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int len = res + 1; len <= min(m, n); ++len) {
                    if (i + len - 1 <= m && j + len - 1 <= n && 
                    presum[i + len - 1][j + len - 1] - presum[i - 1][j + len - 1] - presum[i + len - 1][j - 1] + presum[i - 1][j - 1] <= threshold) {
                        ++res;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return res;
    }
};

void testMaxSideLength() {
    Solution solution;

    vector<vector<int>> mat1 = {{1,1,3,2,4,3,2}, {1,1,3,2,4,3,2}, {1,1,3,2,4,3,2}};
    int threshold1 = 4;
    cout << solution.maxSideLength(mat1, threshold1) << endl;

    vector<vector<int>> mat2 = {{2,2,2,2,2}, {2,2,2,2,2}, {2,2,2,2,2}, {2,2,2,2,2}, {2,2,2,2,2}};
    int threshold2 = 1;
    cout << solution.maxSideLength(mat2, threshold2) << endl;

    vector<vector<int>> mat3 = {{1,1,1,1}, {1,0,0,0}, {1,0,0,0},{1,0,0,0}};
    int threshold3 = 6;
    cout << solution.maxSideLength(mat3, threshold3) << endl;

    vector<vector<int>> mat4 = {{18,70},{61,1},{25,85},{14,40},{11,96},{97,96},{63,45}};
    int threshold4 = 40184;
    cout << solution.maxSideLength(mat4, threshold4) << endl;
}

int main() {
    testMaxSideLength();

    return 0;
}