#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        string record(64, '0');
        for (auto& q : queens) {
            record[q[0] * 8 + q[1]] = '1';
        }

        vector<vector<int>> res;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (i == 0 && j == 0)
                    continue;

                int r = king[0] + i;
                int c = king[1] + j;

                while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                    if (record[r * 8 + c] == '1') {
                        res.push_back({r, c});
                        break;
                    }

                    r += i;
                    c += j;
                }
            }
        }

        return res;
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (auto& r : matrix) {
        for (auto& c : r) {
            cout << c << ", ";
        }

        cout << endl;
    }
    cout << endl;
}

void testQueensAttacktheKing() {
    Solution solution;

    vector<vector<int>> queens1 = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
    vector<int> king1 = {0,0};
    auto res1 = solution.queensAttacktheKing(queens1, king1);
    printMatrix(res1);

    vector<vector<int>> queens2 = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}};
    vector<int> king2 = {3,3};
    auto res2 = solution.queensAttacktheKing(queens2, king2);
    printMatrix(res2);

    vector<vector<int>> queens3 = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    vector<int> king3 = {3,4};
    auto res3 = solution.queensAttacktheKing(queens3, king3);
    printMatrix(res3);
}

int main() {
    testQueensAttacktheKing();

    return 0;
}