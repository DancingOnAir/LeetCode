#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int>& A, vector<int>& B)
{
    int m = A.size();
    int n = B.size();

    if (A.empty() || B.empty())
        return 0;

    if (m > n)
        findLength(B, A);

    int res = 0;
    vector<vector<int>> path(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (A[i - 1] != B[j - 1])
                path[i][j] = 0;
            else
                path[i][j] = path[i - 1][j - 1] + 1;

            if (res < path[i][j])
                res = path[i][j];
        }
    }

    return res;
}

int findLength2(vector<int>& A, vector<int>& B)
{
    int m = A.size();
    int n = B.size();

    if (!m || !n)
        return 0;

    int res = 0;
    vector<int> path(n + 1);

    for (int i = 0; i < m; ++i)
    {
        for (int j = n; j >= 1; --j)
        {
            if (A[i] != B[j - 1])
                path[j] = 0;
            else
                path[j] = path[j - 1] + 1;

            if (res < path[j])
                res = path[j];
        }
    }

    return res;
}

void testFindLength()
{
    vector<int> A = { 1,2,3,2,1 };
    vector<int> B = { 3,2,1,4,7 };

    cout << findLength2(A, B) << endl;
}

int main()
{
    testFindLength();

    getchar();
    return 0;
}