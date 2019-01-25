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

void testFindLength()
{
    vector<int> A = { 1,2,3,2,1 };
    vector<int> B = { 3,2,1,4,7 };

    cout << findLength(A, B) << endl;
}

int main()
{
    testFindLength();

    getchar();
    return 0;
}