//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void setZeroes(vector<vector<int>>& matrix)
//{
//    if (matrix.empty())
//        return;
//
//    auto row = matrix.size();
//    auto col = matrix[0].size();
//
//    vector<vector<bool>> mark(row, vector<bool>(col));
//    for (size_t i = 0; i < row; ++i)
//    {
//        for (size_t j = 0; j < col; ++j)
//        {
//            if (0 == matrix[i][j] && false == mark[i][j])
//            {
//                for (size_t k = 0; k < row; ++k)
//                {
//                    if (matrix[k][j] != 0)
//                    {
//                        matrix[k][j] = 0;
//                        mark[k][j] = true;
//                    }
//
//                    
//                }
//
//                for (size_t l = 0; l < col; ++l)
//                {
//                    if (matrix[i][l] != 0)
//                    {
//                        matrix[i][l] = 0;
//                        mark[i][l] = true;
//                    }
//                }
//
//            }
//        }
//    }
//}
//
//void setZeroes2(vector<vector<int>>& matrix)
//{
//    int row = matrix.size();
//    int col = matrix[0].size();
//
//    if (0 == row || 0 == col)
//        return;
//
//    int last_zero_row = -1;
//    for (int y = row - 1; y >= 0; --y)
//        for (int x = 0; x < col; ++x)
//            if (0 == matrix[y][x])
//            {
//                last_zero_row = y;
//                break;
//            }
//
//    if (-1 == last_zero_row)
//        return;
//
//    for (int y = last_zero_row; y >= 0; --y)
//    {
//        bool is_zero_row = false;
//        for (int x = 0; x < col; ++x)
//        {
//            if (0 == matrix[y][x])
//            {
//                is_zero_row = true;
//                matrix[last_zero_row][x] = 0;
//            }
//        }
//
//        if (is_zero_row)
//        {
//            for (int x = 0; x < col; ++x)
//                matrix[y][x] = 0;
//        }
//    }
//
//    for (int y = 0; y < row; ++y)
//        for (int x = 0; x < col; ++x)
//            if (0 == matrix[last_zero_row][x])
//                matrix[y][x] = 0;
//
//    for (int x = 0; x < col; ++x)
//        matrix[last_zero_row][x] = 0;
//}
//
//void testSetZeroes()
//{
//    vector<vector<int>> matrix = { { 1, 1, 1 },
//                                { 1, 0, 1 },
//                                { 1, 1, 1 } };
//    setZeroes2(matrix);
//
//    for (auto& row : matrix)
//    {
//        for (auto& col : row)
//            cout << col << ", ";
//        cout << endl;
//    }
//}
//
//int main()
//{
//    testSetZeroes();
//    getchar();
//    return 0;
//}