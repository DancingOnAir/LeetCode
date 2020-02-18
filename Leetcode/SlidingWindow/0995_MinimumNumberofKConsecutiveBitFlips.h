#pragma once
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // brute force
    int minKBitFlips2(vector<int>& A, int K)
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

    int minKBitFlips(vector<int>& A, int K)
    {
        int res = 0;
        queue<int> q;

        for (int i = 0; i < A.size(); ++i)
        {
            if (!q.empty() && q.front() + K == i)
                q.pop();

            if (q.size() % 2 == A[i])
            {
                if (i + K > A.size())
                    return -1;

                ++res;
                q.emplace(i);
            }
        }

        return res;
    }
};
