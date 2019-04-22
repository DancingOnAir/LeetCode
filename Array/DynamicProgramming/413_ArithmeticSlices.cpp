#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A)
{
    int n = A.size();

    if (n < 3)
        return 0;

    int preDiff = A[1] - A[0], curDiff = 0;
    int acc = 0, res = 0;

    for (int i = 2; i < A.size(); ++i)
    {
        curDiff = A[i] - A[i - 1];
        if (curDiff == preDiff)
        {
            ++acc;
        }
        else
        {
            while (acc > 0)
            {
                res += acc--;
            }

            acc = 0;
        }

        preDiff = curDiff;
    }

    while (acc > 0)
    {
        res += acc--;
    }

    return res;
}

int numberOfArithmeticSlices2(vector<int>& A)
{
    int n = A.size();

    if (n < 3)
        return 0;

    int res = 0;
    vector<int> dp(n);
    for (int i = 2; i < n; ++i)
    {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            dp[i] = dp[i - 1] + 1;

        res += dp[i];
    }

    return res;
}

void testNumberOfArithmeticSlices()
{
    vector<int> A{ 1, 2, 3, 4, 5 };
    cout << numberOfArithmeticSlices2(A) << endl;
}

int main()
{
    testNumberOfArithmeticSlices();

    getchar();
    return 0;
}