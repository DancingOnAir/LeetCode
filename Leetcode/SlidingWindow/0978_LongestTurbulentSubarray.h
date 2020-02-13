#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    int maxTurbulenceSize(vector<int>& A)
    {
        int n = A.size();
        if (n < 2)
            return n;

        if (n == 2 & A[0] == A[1])
            return 1;

        int left = 0, right = 2, counter = 0, res = 1;

        if (A[0] < A[1])
        {
            counter = 1;
            res = 2;
        }
        else if (A[0] > A[1])
        {
            counter = -1;
            res = 2;
        }

        while (right < A.size())
        {
            if (A[right - 1] < A[right] && counter == -1)
            {
                counter = 1;
            }
            else if (A[right - 1] > A[right] && counter == 1)
            {
                counter = -1;
            }
            else
            {
                counter = 0;
            }

            while (counter == 0 && right < A.size())
            {
                res = max(res, right - left);
                left = right - 1;

                if (A[left] < A[right])
                    counter = 1;
                else if (A[left] > A[right])
                    counter = -1;
                else
                    ++right;
            }

            ++right;
        }

        return max(res, right - left);
    }
};