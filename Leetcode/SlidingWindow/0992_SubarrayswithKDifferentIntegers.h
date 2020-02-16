#pragma once
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct2(vector<int>& A, int K)
    {
        int n = A.size();

        int left = 0, right = 0, count = 0;
        set<pair<int, int>> records;

        for (int i = 0; i < n - K + 1; ++i)
        {
            left = right = i;
            count = 0;
            vector<int> m(n + 1);
            while (right < n)
            {
                if (m[A[right++]]++ == 0)
                {
                    ++count;
                }

                if (count == K)
                {
                    records.emplace(make_pair(left, right));
                }

                while (count == K + 1)
                {
                    if (m[A[left++]]-- == 1)
                    {
                        --count;

                        if (count == K)
                        {
                            records.emplace(make_pair(left, right));
                        }
                    }
                }
            }
        }
        

        return records.size();
    }

    int subarraysWithKDistinct(vector<int>& A, int K)
    {
        unordered_map<int, int> hashLeft, hashRight;
        int left = 0, right = 0, pos = 0, count = 0, res = 0;

        while (pos < A.size())
        {
            hashRight[A[pos]]++;
            hashLeft[A[pos]]++;
            ++pos;

            while (hashRight.size() >= K)
            {
                if (hashRight[A[right]]-- == 1)
                    hashRight.erase(A[right]);
                ++right;
            }

            while (hashLeft.size() > K)
            {
                if (hashLeft[A[left]]-- == 1)
                    hashLeft.erase(A[left]);
                ++left;
            }

            res += right - left;
        }

        return res;
    }
};