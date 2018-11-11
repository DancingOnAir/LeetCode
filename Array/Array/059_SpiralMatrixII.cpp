#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    //≥ı ºªØ
    vector<vector<int>> result(n, vector<int>(n));
    if (n < 0)
        return result;

    int k = 1, i = 0;
    while (k <= n*n)
    {
        int j = i;
        while (j < n - i)
            result[i][j++] = k++;

        j = i + 1;
        while (j < n - i)
            result[j++][n - i - 1] = k++;

        j = n - i - 2;
        while (j > i)
            result[n - i - 1][j--] = k++;

        j = n - i - 1;
        while (j > i)
            result[j--][i] = k++;

        ++i;
    }

    return result;
}

vector<vector<int>> generateMatrix2(int n)
{
    vector<vector<int>> result(n, vector<int>(n));
    if (n < 0)
        return result;

    int k = 1, rowStart = 0, colStart = 0, rowEnd = n - 1, colEnd = n - 1;
    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        for (int i = colStart; i <= colEnd; ++i)
            result[rowStart][i] = k++;
        ++rowStart;

        for (int i = rowStart; i <= rowEnd; ++i)
            result[i][colEnd] = k++;
        --colEnd;

        for (int i = colEnd; i >= colStart; --i)
            result[rowEnd][i] = k++;
        --rowEnd;

        for (int i = rowEnd; i >= rowStart; --i)
            result[i][colStart] = k++;
        ++colStart;
    }

    return result;
}

void display(vector<vector<int>>& matrix)
{
    if (matrix.empty())
        return;

    for (auto& row : matrix)
    {
        for (auto& col : row)
            cout << col << ", ";

        cout << endl;
    }
}

void testGenerateMatrix()
{
    auto result = generateMatrix2(3);
    display(result);
}

int main()
{
    testGenerateMatrix();
    system("pause");
    return 0;
}