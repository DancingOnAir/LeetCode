#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> res {"A", "B", "Draw", "Pending"};
        vector<string> rows(3, string(3, ' '));
        vector<string> cols(3, string(3, ' '));

        int n = moves.size();
        if (n < 5)
            return res[3];

        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                rows[moves[i][0]][moves[i][1]] = 'O';
                cols[moves[i][1]][moves[i][0]] = 'O';
            }
            else {
                rows[moves[i][0]][moves[i][1]] = 'X';
                cols[moves[i][1]][moves[i][0]] = 'X';
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (rows[i] == "XXX" || cols[i] == "XXX")
                return res[0];
            
            if (rows[i] == "OOO" || cols[i] == "OOO")
                return res[1];
        }

        if ((rows[0][0] == rows[1][1] && rows[1][1]== rows[2][2]) || (rows[2][0] == rows[1][1] && rows[1][1]== rows[0][2])) {
            if (rows[1][1] == 'X') {
                return res[0];
            }
            else if (rows[1][1] == 'O') {
                return res[1];
            }
        }

        return n < 9 ? res[3] : res[2];
    }
};

void testTictactoe() {
    Solution solution;

    vector<vector<int>> moves1 = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    cout << solution.tictactoe(moves1) << endl;

    vector<vector<int>> moves2 = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    cout << solution.tictactoe(moves2) << endl;

    vector<vector<int>> moves3 = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
    cout << solution.tictactoe(moves3) << endl;

    vector<vector<int>> moves4 = {{0,0},{1,1}};
    cout << solution.tictactoe(moves4) << endl;
}

int main() {
    testTictactoe();

    return 0;
}