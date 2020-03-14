#pragma once
#include <vector>
using namespace std;

struct SegmentTreeNode
{
    long long start_;
    long long end_;
    int count_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    SegmentTreeNode(long long start, long long end) : start_(start), end_(end), count_(0), left_(nullptr), right_(nullptr)
    {

    }
};

class Solution
{
private:
    SegmentTreeNode* build(long long start, long long end)
    {
        if (start > end)
            return nullptr;

        auto root = new SegmentTreeNode(start, end);
        if (start == end)
        {
            return root;
        }

        long long mid = start + ((end - start) >> 1);
        root->left_ = build(start, mid);
        root->right_ = build(mid + 1, end);

        return root;
    }

    void updateSegmentTree(SegmentTreeNode* root, long long val)
    {
        if (!root || root->start_ > val || root->end_ < val)
            return;
        
        if (val == root->start_ && val == root->end_)
        {
            root->count_ += 1;
            return;
        }

        updateSegmentTree(root->left_, val);
        updateSegmentTree(root->right_, val);

        root->count_ = root->left_->count_ + root->right_->count_;
    }

    int querySegmentTree(SegmentTreeNode* root, long long start, long long end)
    {
        if (!root || start > root->end_ || end < root->start_)
            return 0;

        if (start <= root->start_, end > root->end_)
            return root->count_;

        return querySegmentTree(root->left_, start, end) + querySegmentTree(root->right_, start, end);
    }

public:
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0 || n == 1)
            return 0;

        //int minVal = abs(*min_element(nums.begin(), nums.end()));
        //for (int& num : nums)
        //    num += minVal;

        int res = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        SegmentTreeNode* root = build(0, maxVal * 2);

        reverse(nums.begin(), nums.end());
        for (int num : nums)
        {
            res += querySegmentTree(root, 0, num);
            updateSegmentTree(root, (long long)num * 2);
        }

        return res;
    }
};
