#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(int m, int n, int N, int i, int j, int& res)
{
    if (N < 0)
    {
        return;
    }

    if (i < 0 || i >= m || j < 0 || j >= n)
    {
        ++res;
        return;
    }

    backtracking(m, n, N - 1, i + 1, j, res);
    backtracking(m, n, N - 1, i - 1, j, res);
    backtracking(m, n, N - 1, i, j + 1, res);
    backtracking(m, n, N - 1, i, j - 1, res);
}

int findPaths(int m, int n, int N, int i, int j)
{
    if (m < 1 || n < 1 || N < 1 || i < 0 || j < 0)
        return 0;

    int res = 0;
    backtracking(m, n, N, i, j, res);

    return res;

}

void testFindPaths()
{
    cout << findPaths(2, 2, 2, 0, 0) << endl;
    cout << findPaths(1, 3, 3, 0, 1) << endl;
}

int main()
{
    testFindPaths();
    getchar();
    return 0;
}