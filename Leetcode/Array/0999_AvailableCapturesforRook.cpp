#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rowOfR = 0, colOfR = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    rowOfR = i;
                    colOfR = j;
                    break;
                }
            }
        }

        int res = 0;
        vector<vector<int>> directors {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& d : directors) {
            for (int x = rowOfR + d[0], y = colOfR + d[1]; 0 <= x && x < 8 && 0 <= y && y < 8; x += d[0], y += d[1]) {
                if (board[x][y] == 'p') 
                    ++res;
                if (board[x][y] != '.')
                    break;
            }
        }

        return res;
    }
};

void testNumRookCaptures() {
    Solution solution;
    
    vector<vector<char>> board1 {{'.','.','.','.','.','.','.','.'},
                                {'.','.','.','p','.','.','.','.'},
                                {'.','.','.','R','.','.','.','p'},
                                {'.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.'},
                                {'.','.','.','p','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.'}};
    cout << solution.numRookCaptures(board1) << endl;

    vector<vector<char>> board2 {{'.','.','.','.','.','.','.','.'},
                                {'.','p','p','p','p','p','.','.'},
                                {'.','p','p','B','p','p','.','.'},
                                {'.','p','B','R','B','p','.','.'},
                                {'.','p','p','B','p','p','.','.'},
                                {'.','p','p','p','p','p','.','.'},
                                {'.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.'}};
    cout << solution.numRookCaptures(board2) << endl;

    vector<vector<char>> board3 {{'.','.','.','.','.','.','.','.'},
                                {'.','.','.','p','.','.','.','.'},
                                {'.','.','.','p','.','.','.','.'},
                                {'p','p','.','R','.','p','B','.'},
                                {'.','.','.','.','.','.','.','.'},
                                {'.','.','.','B','.','.','.','.'},
                                {'.','.','.','p','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.'}};
    cout << solution.numRookCaptures(board3) << endl;
}

int main() {
    testNumRookCaptures();
    return 0;
}