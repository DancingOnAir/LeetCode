#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        if (nums.empty())
            return vector<int>();

        int n = nums.size();
        vector<int> res;
        vector<int> sortedNums;
        int count = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            auto iter = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]);
            res.emplace_back(iter - sortedNums.begin());
            sortedNums.insert(iter, nums[i]);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};