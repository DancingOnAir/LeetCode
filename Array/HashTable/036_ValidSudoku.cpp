//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//
//
//bool isValidSudoku2(vector<vector<char>>& board)
//{
//    vector<char> nums = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
//    unordered_map<char, int> m, n;
//
//    for (int i = 0; i < 9; ++i)
//    {
//        for (int j = 0; j < 9; ++j)
//        {
//            if (board[i][j] != '.')
//            {
//                if (m.count(board[i][j]))
//                    return false;
//                else
//                    m[board[i][j]] = 1;
//            }
//
//            if (board[j][i] != '.')
//            {
//                if (n.count(board[j][i]))
//                    return false;
//                else
//                    n[board[j][i]] = 1;
//            }
//
//        }
//        m.clear();
//        n.clear();
//    }
//
//    for (int col = 0; col < 3; ++col)
//    {
//        for (int row = 0; row < 3; ++row)
//        {
//            for (int i = col * 3; i < col * 3 + 3; ++i)
//            {
//                for (int j = row * 3; j < row * 3 + 3; ++j)
//                {
//                    if (board[i][j] != '.')
//                    {
//                        if (m.count(board[i][j]))
//                            return false;
//                        m[board[i][j]] = 1;
//                    }
//                }
//            }
//            m.clear();
//        }
//    }
//
//    return true;
//}
//
//bool isValidSudoku(vector<vector<char>>& board)
//{
//    vector<short> col(9);
//    vector<short> row(9);
//    vector<short> block(9);
//
//    for (int i = 0; i < 9; ++i)
//    {
//        for (int j = 0; j < 9; ++j)
//        {
//            if (board[i][j] != '.')
//            {
//                int idx = 1 << (board[i][j] - '0');
//                if (idx & col[j] || idx & row[i] || idx & block[i / 3 * 3 + j / 3])
//                    return false;
//
//                col[j] |= idx;
//                row[i] |= idx;
//                block[i / 3 * 3 + j / 3] |= idx;
//            }
//        }
//    }
//
//    return true;
//}
//
//void testIsValidSudoku()
//{
//    vector<vector<char>> board1 = {
//            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };
//    cout << (isValidSudoku(board1) ? "True" : "False") << endl;
//
//    vector<vector<char>> board2 = {
//            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
//            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };
//    cout << (isValidSudoku(board2) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testIsValidSudoku();
//
//    getchar();
//    return 0;
//}