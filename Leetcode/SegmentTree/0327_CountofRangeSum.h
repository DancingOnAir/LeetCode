#pragma once
#include <vector>
#include <set>
using namespace std;
struct SegmentTreeNode
{
    long long min_;
    long long max_;
    int count_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;

    SegmentTreeNode(long long min, long long max) : min_(min), max_(max), count_(0), left_(nullptr), right_(nullptr)
    {

    }
};

class Solution
{
private:
    SegmentTreeNode* root_;

    SegmentTreeNode* build(vector<long long>& nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        SegmentTreeNode* root = new SegmentTreeNode(nums[start], nums[end]);
        if (start == end)
        {
            return root;
        }

        int mid = start + ((end - start) >> 1);
        root->left_ = build(nums, start, mid);
        root->right_ = build(nums, mid + 1, end);

        return root;
    }

    void update(SegmentTreeNode* root, long long val)
    {
        if (!root || val < root->min_ || val > root->max_)
            return;

        root->count_++;
        if (root->min_ == root->max_)
            return;
        
        update(root->left_, val);
        update(root->right_, val);
    }

    int query(SegmentTreeNode* root, long long min, long long max)
    {
        if (!root || max < root->min_ || min > root->max_)
            return 0;

        if (min <= root->min_ && max >= root->max_)
            return root->count_;
        
        return query(root->left_, min, max) + query(root->right_, min, max);
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        if (nums.empty() || (lower > upper))
            return 0;

        int n = nums.size();
        vector<long long> presum;
        
        long long tmpSum = 0;
        for (int x : nums)
        {
            tmpSum += x;
            presum.emplace_back(tmpSum);
        }

        sort(presum.begin(), presum.end());
        presum.erase(unique(presum.begin(), presum.end()), presum.end());

        root_ = build(presum, 0, presum.size() - 1);
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            update(root_, tmpSum);
            tmpSum -= nums[i];
            res += query(root_, lower + tmpSum, upper + tmpSum);
        }

        return res;
    }

    int countRangeSum1(vector<int>& nums, int lower, int upper)
    {
        if (nums.empty() || (lower > upper))
            return 0;

        multiset<long long> ms;
        ms.emplace(0);

        long long presum = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            presum += nums[i];

            auto lo = lower_bound(ms.begin(), ms.end(), presum - upper);
            auto hi = upper_bound(ms.begin(), ms.end(), presum - lower);

            res += distance(lo, hi);
            ms.emplace(presum);
        }

        return res;
    }
};

