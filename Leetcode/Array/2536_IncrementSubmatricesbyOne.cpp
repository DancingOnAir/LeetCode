#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
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
