#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        if (n < 2)
            return n;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1]; });

        vector<int> lastInterval(intervals[0]);
        int res = n;
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] >= lastInterval[0] && intervals[i][1] <= lastInterval[1])
            {
                --res;
            }
            else
            {
                lastInterval = intervals[i];
            }
        }

        return res;
    }
};
