#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int>& A, int K)
    {
        int res = 0;

        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] == 0)
            {
                if (i + K > A.size())
                    return -1;

                ++res;
                for (int j = i; j < i + K; ++j)
                    A[j] ^= 1;
            }
        }

        return res;
    }
};
