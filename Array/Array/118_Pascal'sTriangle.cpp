#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    if (numRows <= 0)
        return result;

    vector<int> col;
    for (int i = 0; i < numRows; ++i)
    {
        if (0 == i)
            result.emplace_back(vector<int>({1}));
        else if (1 == i)
            result.emplace_back(vector<int>({ 1, 1 }));
        else
        {
            for (int j = 0; j <= i; ++j)
            {
                if (0 == j)
                    col.emplace_back(result[i - 1][0]);
                else if(i == j)
                    col.emplace_back(result[i - 1][i - 1]);
                else
                    col.emplace_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result.emplace_back(col);
            col.clear();
        }
    }

    return result;
}

vector<vector<int>> generate2(int numRows)
{
    vector<vector<int>> result(numRows);

    for (int i = 0; i < numRows; ++i)
    {
        result[i].resize(i + 1);
        result[i][0] = result[i][i] = 1;

        for (int j = 1; j < i; ++j)
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
    }

    return result;
}

void testGenerate()
{
    auto result = generate2(5);

    for (auto& row : result)
    {
        for (auto& col : row)
            cout << col << ", ";
        cout << endl;
    }
}

int main()
{
    testGenerate();
    getchar();
}