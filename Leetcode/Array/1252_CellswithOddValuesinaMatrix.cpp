#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> rows(n, false), cols(m, false);
        for (auto& i : indices) {
            rows[i[0]] = !rows[i[0]];
            cols[i[1]] = !cols[i[1]];
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rows[i] ^ cols[j]) {
                    ++res;
                }
            }
        }

        return res;
    }

    int oddCells1(int n, int m, vector<vector<int>>& indices) {
        vector<int> countRow(n), countCol(m);
        for (auto& i : indices) {
            ++countRow[i[0]];
            ++countCol[i[1]];
        }

        int res = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if ((countRow[r] + countCol[c]) & 1)
                    ++res;
            }
        }

        return res;
    }
};

void testOddCells() {
    Solution solution;

    int n1 = 2, m1 = 3;
    vector<vector<int>> indices1 = {{0, 1},{1, 1}};
    cout << solution.oddCells(n1, m1, indices1) << endl;

    int n2 = 2, m2 = 2;
    vector<vector<int>> indices2 = {{1, 1},{0, 0}};
    cout << solution.oddCells(n2, m2, indices2) << endl;
}

int main() {
    testOddCells();

    return 0;
}