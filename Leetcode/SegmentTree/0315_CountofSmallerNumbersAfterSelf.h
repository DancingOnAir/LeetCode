#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> res;

public:
    void merge(vector<vector<int>>& nums, int lo, int mid, int hi)
    {
        if (nums[mid][0] < nums[mid + 1][0])
            return;

        int i = lo, j = mid + 1;
        vector<vector<int>> sortNums;

        while (i <= mid && j <= hi)
        {
            if (nums[i][0] <= nums[j][0])
            {
                res[nums[i][1]] += j - mid - 1;
                sortNums.emplace_back(nums[i++]);
            }
            else
            {
                sortNums.emplace_back(nums[j++]);
            }
        }

        while (i <= mid)
        {
            res[nums[i][1]] += j - mid - 1;
            sortNums.emplace_back(nums[i++]);
        }

        while (j <= hi)
        {
            sortNums.emplace_back(nums[j++]);
        }

        for (int m = 0, n = lo; m < sortNums.size(); ++m, ++n)
            nums[n] = sortNums[m];
    }

    void mergeSort(vector<vector<int>>& nums, int lo, int hi)
    {
        if (lo >= hi)
            return;

        int mid = lo + ((hi - lo) >> 1);
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }

    // i & -i represents the weight of a binary number with the lowest bit of 1, eg. 1100->100->4, 1110->10->2, 1001->1->1
    vector<int> countSmaller(vector<int>& nums)
    {
        if (nums.empty())
            return {};

        int n = nums.size();
        if (1 == n)
            return { 0 };

        vector<vector<int>> hold;
        for (int i = 0; i < n; ++i)
            hold.emplace_back(vector<int>({ nums[i], i }));

        res.resize(n);

        mergeSort(hold, 0, n - 1);
        return res;
    }

    vector<int> countSmaller1(vector<int>& nums)
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