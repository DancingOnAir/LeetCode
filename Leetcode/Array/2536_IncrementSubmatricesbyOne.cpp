#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n));
        for (auto& q : queries) {
            ++res[q[0]][q[1]];
            if (q[2] + 1 < n) {
                --res[q[2] + 1][q[1]];
            }

            if (q[3] + 1 < n) {
                --res[q[0]][q[3] + 1];
            }

            if ((q[2] + 1 < n) && (q[3] + 1 < n)) {
                ++res[q[2] + 1][q[3] + 1];
            }
        }
        // sweep line by row
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                res[r][c] += res[r - 1][c];
            }
        }
        // sweep line by col
        for (int r = 0; r < n; ++r) {
            for (int c = 1; c < n; ++c) {
                res[r][c] += res[r][c - 1];
            }
        }
        return res;
    }

    // # https://leetcode.com/problems/increment-submatrices-by-one/solutions/3052675/python3-sweep-line-range-addition-w-visualization-clean-concise/
    // # Time complexity: O(n2+nq) ≈ O(nq) if q≫n; 这里q是queries的长度
    vector<vector<int>> rangeAddQueries1(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n));
        for (auto& q : queries) {
            for (int r = q[0]; r < q[2] + 1; ++r) {
                ++res[r][q[1]];
                if (q[3] + 1 < n) {
                    --res[r][q[3] + 1];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                res[i][j] += res[i][j - 1];
            }
        }
        return res;
    }
};

void print(vector<vector<int>>& mat) {
    if (mat.empty())
        return;

    for (auto& r : mat) {
        for (auto& c : r) {
            cout << c << ", ";
        }
        cout << endl;
    }
}

void testRangeAddQueries() {
    Solution solution;
    vector<vector<int>> q1{{1,1,2,2},{0,0,1,1}};
    auto res1 = solution.rangeAddQueries(3, q1);
    print(res1);
    vector<vector<int>> q2{{0,0,1,1}};
    auto res2 = solution.rangeAddQueries(2, q2);
    print(res2);
}

int main() {
    testRangeAddQueries();
    return 0;
}
