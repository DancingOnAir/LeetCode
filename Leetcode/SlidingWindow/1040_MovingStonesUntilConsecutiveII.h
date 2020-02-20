#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int>& stones)
    {
        sort(stones.begin(), stones.end());

        int n = stones.size();
        int mx = stones[n - 1] - stones[0] + 1 - n;
        int leftIntervals = stones[1] - stones[0] - 1;
        int rightIntervals = stones[n - 1] - stones[n - 2] - 1;
        int minIntervals = min(leftIntervals, rightIntervals);

        mx -= minIntervals;
        int mi = mx;

        int left = 0, right = 0;
        for (; left < n; ++left)
        {
            while (right + 1 < n && stones[right + 1] - stones[left] + 1 <= n)
            {
                ++right;
            }

            int cost = n - (right - left + 1);
            if (right - left + 1 == n - 1 && stones[right] - stones[left] + 1 == n - 1)
                cost = 2;

            mi = min(mi, cost);
        }

        return vector<int>{mi, mx};
    }
};