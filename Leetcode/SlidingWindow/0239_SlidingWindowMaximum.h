#pragma once
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.empty() || k < 1 || k > nums.size())
            return vector<int>();

        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.emplace_back(i);
            if (i >= k - 1)
                res.emplace_back(nums[dq.front()]);
        }

        return res;
    }
};