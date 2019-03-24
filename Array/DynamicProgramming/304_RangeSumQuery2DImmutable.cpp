#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix)
    {
        numOfRow = matrix.size();
        numOfCol = numOfRow > 0? matrix[0].size():0;

        accu.emplace_back(0);

        for (auto& row : matrix)
        {
            for (auto& col : row)
            {
                accu.emplace_back(accu.back() + col);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        for (int i = row1; i <= row2; ++i)
        {
            res += accu[i * numOfCol + col2 + 1] - accu[i * numOfCol + col1];
        }

        return res;
    }

private:
    vector<int> accu;
    int numOfRow;
    int numOfCol;
};

void testNumMatrix()
{
    vector<vector<int>> matrix = { {3, 0, 1, 4, 2},
                                {5, 6, 3, 2, 1},
                                {1, 2, 0, 1, 5},
                                {4, 1, 0, 1, 7},
                                {1, 0, 3, 0, 5} };


    NumMatrix numMatrix(matrix);

    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
}

int main()
{
    testNumMatrix();

    getchar();
    return 0;
}