#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int m = A.size();
    if (0 == m)
        return 0;

    int n = A[0].size();
    if (0 == n)
        return 0;

    vector<pair<int, int>> A1;
    vector<pair<int, int>> B1;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (1 == A[i][j])
                A1.emplace_back(make_pair(i, j));

            if (1 == B[i][j])
                B1.emplace_back(make_pair(i, j));
        }
    }

    unordered_map<int, int> move;
    for (auto& ca : A1)
    {
        for (auto& cb : B1)
        {
            int key = (ca.first - cb.first) * 100 + (ca.second - cb.second);
            move[key]++;
        }
    }

    int res = 0;
    for (auto& iter : move)
        res = max(res, iter.second);

    return res;
}

void testsLargestOverlap()
{
    vector<vector<int>> A = { {1, 1, 0},
                            {0, 1, 0},
                            {0, 1, 0} };

    vector<vector<int>> B = { {0, 0, 0},
                            {0, 1, 1},
                            {0, 0, 1} };

    cout << largestOverlap(A, B) << endl;
}

int main()
{
    testsLargestOverlap();

    getchar();
    return 0;
}