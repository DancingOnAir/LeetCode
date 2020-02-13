#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    int compareValue(int lhs, int rhs)
    {
        if (lhs == rhs)
            return 0;

        return lhs < rhs ? -1 : 1;
    }

    int maxTurbulenceSize(vector<int>& A)
    {
        int n = A.size();
        if (n < 2)
            return n;

        int res = 1;
        int anchor = 0;
        for (int i = 1; i < n; ++i)
        {
            int c = compareValue(A[i - 1], A[i]);

            if (i == n - 1 || c * compareValue(A[i], A[i + 1]) != -1)
            {
                if (c != 0)
                    res = max(res, i - anchor + 1);
                anchor = i;
            }

        }

        return res;
    }
};