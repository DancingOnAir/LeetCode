#pragma once
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.empty())
            return vector<double>();

        vector<double> res;
        int left = 0, right = 0, counter = 0;
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            dq.emplace_back(i);
        }

        return res;
    }
};