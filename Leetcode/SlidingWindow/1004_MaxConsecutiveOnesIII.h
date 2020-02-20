#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int>& A, int K)
    {
        int left = 0, right = 0;
        vector<int> m(2);

        while (right < A.size())
        {
            m[A[right++]]++;
            if (right - left - m[1] > K)
                m[A[left++]]--;
        }

        return right - left;
    }
};
