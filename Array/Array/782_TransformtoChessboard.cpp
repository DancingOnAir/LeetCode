#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int movesToChessboard(vector<vector<int>>& board)
{
    int n = board.size();
    int rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;

    if (n < 2 || n > 30)
        return -1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j])
                return -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        rowSum += board[0][i];
        colSum += board[i][0];
        rowSwap += board[i][0] == i % 2;
        colSwap += board[0][i] == i % 2;
    }

    if (rowSum < n / 2 || rowSum > (n + 1) / 2)
        return -1;

    if (colSum < n / 2 || colSum > (n + 1) / 2)
        return -1;

    if (n % 2)
    {
        if (colSwap % 2)
            colSwap = n - colSwap;

        if (rowSwap % 2)
            rowSwap = n - rowSwap;
    }
    else
    {
        colSwap = min(n - colSwap, colSwap);
        rowSwap = min(n - rowSwap, rowSwap);
    }

    return (colSwap + rowSwap) / 2;
}

void testMovesToChessboard()
{
    vector<vector<int>> board1 = {{0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}};
    cout << movesToChessboard(board1) << endl;

    vector<vector<int>> board2 = {{1, 0}, {1, 0}};
    cout << movesToChessboard(board2) << endl;
}

int main()
{
    testMovesToChessboard();

    getchar();
    return 0;
}