#include <iostream>
#include <vector>

using namespace std;

bool isValidElement(int n, int m, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;

    return true;
}

bool isToeplitzMatrix1(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    if (0 == m)
        return false;

    int n = matrix[0].size();
    if (0 == n)
        return false;

    for (int i = 0; i < m - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (matrix[i][j] != matrix[i + 1][j + 1])
                return false;
        }
    }

    return true;
}

bool isToeplitzMatrix2(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    if (0 == m)
        return false;

    int n = matrix[0].size();
    if (0 == n)
        return false;

    for (int i = 0; i + n + 1 < m * n; ++i)
    {
        int nextPos = i + n + 1;
        if (i % n != (n - 1) && matrix[nextPos / n][nextPos % n] != matrix[i / n][i % n])
            return false;
    }

    return true;
}

void testIsToeplitzMatrix()
{
    vector<vector<int>> matrix1 = { {1, 2, 3, 4},
                                    {5, 1, 2, 3},
                                    {9, 5, 1, 2} };

    vector<vector<int>> matrix2 = {{11, 74, 0, 93}, 
                                { 40, 11, 74, 7 }};

    cout << (isToeplitzMatrix2(matrix1) ? "true" : "false") << endl;
    cout << (isToeplitzMatrix2(matrix2) ? "true" : "false") << endl;
}

int main()
{
    testIsToeplitzMatrix();

    getchar();
    return 0;
}