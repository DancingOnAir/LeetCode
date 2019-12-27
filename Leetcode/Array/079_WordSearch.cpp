//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool helper(vector<vector<char>>& board, int x, int y, string& word, int start)
//{
//    if (x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() || board[x][y] != word[start])
//        return false;
//
//    if (start == word.size() - 1)
//        return true;
//
//    char cur = board[x][y];
//    board[x][y] = '*';
//
//    if (helper(board, x + 1, y, word, start + 1) ||
//        helper(board, x - 1, y, word, start + 1) ||
//        helper(board, x, y + 1, word, start + 1) ||
//        helper(board, x, y - 1, word, start + 1))
//        return true;
//
//    board[x][y] = cur;
//
//    return false;
//}
//
//bool exist(vector<vector<char>>& board, string word)
//{
//    if (word.empty() || board.empty() || board[0].empty())
//        return false;
//
//    for (int i = 0; i < board.size(); ++i)
//        for (int j = 0; j < board[0].size(); ++j)
//            if (helper(board, i, j, word, 0))
//                return true;
//
//    return false;
//}
//
//void testExist()
//{
//    vector<vector<char>> board = { { 'A', 'B', 'C', 'E' }, 
//                                { 'S', 'F', 'C', 'S' }, 
//                                { 'A', 'D', 'E', 'E' } };
//    string word = "ABCCED";
//    string word2 = "SEE";
//    string word3 = "ABCB";
//    bool result = exist(board, word);
//    cout << (result ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testExist();
//    getchar();
//}