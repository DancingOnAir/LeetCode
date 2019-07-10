#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxRotateFunction(vector<int>& A)
{
    if (A.empty())
        return 0;

    int res = INT_MIN;
    int len = A.size();
    for (int i = 0; i < len; ++i)
    {
        int sum = 0;
        for (int j = 0; j < len; ++j)
        {
            sum += j * A[((-i + len) % len + j) % len];
        }
        res = max(res, sum);
    }

    return res;
}

void testMaxRotateFunction()
{
    vector<int> A1 = { 4, 3, 2, 6 };
    cout << maxRotateFunction(A1) << endl;
}

int main()
{
    testMaxRotateFunction();

    getchar();
    return 0;
}