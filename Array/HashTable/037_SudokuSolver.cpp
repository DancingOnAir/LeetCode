#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> m_row(9, vector<int>(10, 0));
vector<vector<int>> m_col(9, vector<int>(10, 0));
vector<vector<vector<int>>> m_block(3, vector<vector<int>>(3, vector<int>(10, 0)));

bool isValidSudoku(vector<vector<char>>& board, int i, int j, char c)
{
    if (m_row[i][c - '0'] == 1)
        return false;

    if (m_col[j][c - '0'] == 1)
        return false;

    if (m_block[i / 3][j / 3][c - '0'] == 1)
        return false;

    return true;
}

bool solveSudoku(vector<vector<char>>& board, int i, int j)
{
    if (i == 9)
        return true;

    if (j == 9)
        return solveSudoku(board, i + 1, 0);

    if (board[i][j] != '.')
        return solveSudoku(board, i, j + 1);

    for (char c = '1'; c <= '9'; ++c)
    {
        if (isValidSudoku(board, i, j, c))
        {
            board[i][j] = c;
            m_row[i][c - '0'] = 1;
            m_col[j][c - '0'] = 1;
            m_block[i / 3][j / 3][c - '0'] = 1;

            if (solveSudoku(board, i, j + 1))
                return true;

            board[i][j] = '.';
            m_row[i][c - '0'] = 0;
            m_col[j][c - '0'] = 0;
            m_block[i / 3][j / 3][c - '0'] = 0;
        }
    }

    return false;
}



void solveSudoku(vector<vector<char>>& board)
{
    if (board.empty())
        return;

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                m_row[i][board[i][j] - '0'] = 1;
                m_col[j][board[i][j] - '0'] = 1;
                m_block[i / 3][j / 3][board[i][j] - '0'] = 1;
            }
        }
    }

    solveSudoku(board, 0, 0);
}

void display(vector<vector<char>>& board)
{
    if (board.empty())
        return;

    for (auto& r : board)
    {
        for (auto& c : r)
            cout << c << ", ";
        cout << endl;
    }
}

void testSolveSudoku()
{
    vector<vector<char>> board1 = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(board1);

    vector<vector<char>> board2 = {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(board2);
}

int main()
{
    testSolveSudoku();

    getchar();
    return 0;
}