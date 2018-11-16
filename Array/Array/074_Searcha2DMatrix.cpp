#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    size_t row = matrix.size();
    if (0 == row)
        return false;

    size_t col = matrix[0].size();
    if (0 == col)
        return false;

    for (size_t i = 0; i < row; ++i)
    {
        if (target == matrix[i][col - 1])
            return true;
        else if (target > matrix[i][col - 1])
            continue;
        else
        {
            for (size_t j = 0; j < col; ++j)
            {
                if (target == matrix[i][j])
                    return true;
            }

            return false;
        }
    }

    return false;
}

void testSearchMatrix()
{
    vector<vector<int>> matrix = { {1, 3, 5, 7}, 
                                {10, 11, 16, 20},
                                {23, 30, 34, 50} };

    bool result = searchMatrix(matrix, 3);
    cout << (result ? "true" : "false") << endl;
}


int main()
{
    testSearchMatrix();
    getchar();
    return 0;
}