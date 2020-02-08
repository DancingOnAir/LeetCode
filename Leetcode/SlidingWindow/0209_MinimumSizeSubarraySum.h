#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int res = INT_MAX, left = 0, right = 0, sum = 0;

        while (right < nums.size())
        {
            sum += nums[right++];
            while (sum >= s)
            {
                res = min(res, right - left + 1);
                sum -= nums[left++];
            }
        }

        return res;
    }
};