#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;
    unsigned int m = matrix.size();
    if (0 == m)
        return result;

    unsigned int n = matrix[0].size();
    if (0 == n)
        return result;

    int len = m * n;
    result.resize(len);
    int index = 0, rowStart = 0, colStart = 0, rowEnd = m - 1, colEnd = n - 1;
    while (index < len)
    {
        for (int i = colStart; i <= colEnd; ++i)
            if (index < len)
                result[index++] = matrix[rowStart][i];
            else
                break;

        ++rowStart;

        for (int i = rowStart; i <= rowEnd; ++i)
            if (index < len)
                result[index++] = matrix[i][colEnd];
            else
                break;
        --colEnd;

        for (int i = colEnd; i >= colStart; --i)
            if (index < len)
                result[index++] = matrix[rowEnd][i];
            else
                break;
        --rowEnd;

        for (int i = rowEnd; i >= rowStart; --i)
            if (index < len)
                result[index++] = matrix[i][colStart];
            else
                break;
        ++colStart;
    }

    return result;
}

void display(vector<int>& nums)
{
    if (nums.empty())
        return;

    for (auto& x : nums)
        cout << x << ",";
    cout << endl;
}

void testSpiralOrder()
{
    vector<vector<int>> matrix = { { 1, 2, 3, 4 },
                                    { 5, 6, 7, 8 },
                                    { 9, 10, 11, 12 } };
    auto result = spiralOrder(matrix);
    display(result);
}

int main()
{
    testSpiralOrder();
    getchar();
}