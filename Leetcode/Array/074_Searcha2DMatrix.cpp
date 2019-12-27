//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//bool searchMatrix(vector<vector<int>>& matrix, int target)
//{
//    size_t row = matrix.size();
//    if (0 == row)
//        return false;
//
//    size_t col = matrix[0].size();
//    if (0 == col)
//        return false;
//
//    for (size_t i = 0; i < row; ++i)
//    {
//        if (target == matrix[i][col - 1])
//            return true;
//        else if (target > matrix[i][col - 1])
//            continue;
//        else
//        {
//            for (size_t j = 0; j < col; ++j)
//            {
//                if (target == matrix[i][j])
//                    return true;
//            }
//
//            return false;
//        }
//    }
//
//    return false;
//}
//
//bool searchMatrix2(vector<vector<int>>& matrix, int target)
//{
//    int row = matrix.size();
//    if (0 == row)
//        return false;
//
//    int col = matrix[0].size();
//    if (0 == col)
//        return false;
//
//    int start = 0;
//    int end = row * col - 1;
//    while (start <= end)
//    {
//        int mid = start + (end - start) / 2;
//        if (matrix[mid / col][mid % col] == target)
//            return true;
//        else if (matrix[mid/col][mid%col] > target)
//            end = mid - 1;
//        else
//            start = mid + 1;
//
//    }
//
//    return false;
//}
//
//void testSearchMatrix()
//{
//    vector<vector<int>> matrix = { {1, 3, 5, 7}, 
//                                {10, 11, 16, 20},
//                                {23, 30, 34, 50} };
//    vector<vector<int>> matrix2 = { {1, 1} };
//    bool result = searchMatrix2(matrix2, 2);
//    cout << (result ? "true" : "false") << endl;
//}
//
//
//int main()
//{
//    testSearchMatrix();
//    getchar();
//    return 0;
//}