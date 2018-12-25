#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool toggleValue(vector<vector<int>>& board, int x, int y)
{
    int count = 0;

    for (int i = -1; i < 2; ++i)
    {
        for (int j = -1; j < 2; ++j)
        {
            if (i == 0 && j == 0)
                continue;

            if (x + i < 0 || x + i >= board.size() || y + j < 0 || y + j >=board[0].size())
                continue;

            if (board[x + i][y + j])
                ++count;
        }
    }

    if ((board[x][y] == 1 && count < 2) || (board[x][y] == 1 && count > 3))
        return true;

    if (board[x][y] == 0 && count == 3)
        return true;

    return false;
}

void gameOfLife(vector<vector<int>>& board)
{
    if (board.empty() || board[0].empty())
        return;

    int rows = board.size();
    int cols = board[0].size();
    vector<pair<int, int>> changes;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (toggleValue(board, i, j))
                changes.emplace_back(make_pair(i, j));
        }
    }

    for (auto& pos : changes)
        board[pos.first][pos.second] = !board[pos.first][pos.second];
}

void testGameOfLife()
{
    vector<vector<int>> board = { {0,1,0},
                                {0,0,1},
                                {1,1,1},
                                {0,0,0} };

    gameOfLife(board);

    for (auto& row : board)
    {
        for (auto& col : row)
            cout << col << " ";
        cout << endl;
    }
}

int main()
{
    testGameOfLife();

    getchar();
    return 0;
}