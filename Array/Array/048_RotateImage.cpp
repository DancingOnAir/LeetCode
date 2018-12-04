#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return;

    std::reverse(matrix.begin(), matrix.end());

    auto m = matrix.size();
    auto n = matrix[0].size();
    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

void display(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return;

    for (auto& row : matrix)
    {
        for (auto& col : row)
            cout << col << ", ";
        cout << endl;
    }
}

void testRotate()
{
    vector<vector<int>> matrix = {{5, 1, 9,11 },
                                {2, 4, 8,10 },
                                {13, 3, 6, 7 },
                                {15,14,12,16 }};

    rotate(matrix);
    display(matrix);
}

int main()
{
    testRotate();
    getchar();
}