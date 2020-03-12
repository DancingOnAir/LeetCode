#pragma once
#include <vector>
using namespace std;
struct SegmentTreeNode
{
    int start_;
    int end_;
    int sum_;
    int lazy_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;

    SegmentTreeNode(int start, int end) : start_(start), end_(end), sum_(0), lazy_(0), left_(nullptr), right_(nullptr)
    {

    }

    void updateByValue(int val)
    {
        lazy_ += val;
        sum_ += (end_ - start_ + 1) * val;
    }
};

class Solution
{
private:
    SegmentTreeNode* root_;

    void pushUp(SegmentTreeNode* root)
    {
        root->sum_ = root->left_->sum_ + root->right_->sum_;
    }

    void pushDown(SegmentTreeNode* root)
    {
        int lazy = root->lazy_;
        if (lazy)
        {
            root->left_->updateByValue(lazy);
            root->right_->updateByValue(lazy);
            root->lazy_ = 0;
        }
    }

    SegmentTreeNode* build(vector<int>& nums, int start, int end, vector<int>& sums)
    {
        if (start > end)
            return nullptr;

        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        if (start == end)
        {
            root->sum_ = nums[start];
            sums.emplace_back(root->sum_);

            return root;
        }

        int mid = start + ((end - start) >> 1);
        root->left_ = build(nums, start, mid, sums);
        root->right_ = build(nums, mid + 1, end, sums);
        pushUp(root);
        sums.emplace_back(root->sum_);

        return root;
    }

    //void update(SegmentTreeNode* root, int i, int val)
    //{
    //    if (!root)
    //        return;

    //    if (root->start_ == i && root->end_ == i)
    //    {
    //        root->sum_ = val;
    //        return;
    //    }

    //    pushDown(root);
    //    int mid = root->start_ + ((root->end_ - root->start_) >> 1);
    //    if (i <= mid)
    //        update(root->left_, i, val);
    //    else
    //        update(root->right_, i, val);

    //    pushUp(root);
    //}

    void query(SegmentTreeNode* root, int start, int end, int& sum)
    {
        if (start > root->end_ || end < root->start_)
            return;

        if (start <= root->start_ && end >= root->end_)
        {
            sum += root->sum_;
            return;
        }

        pushDown(root);
        int mid = root->start_ + ((root->end_ - root->start_) >> 1);
        query(root->left_, start, end, sum);
        query(root->right_, start, end, sum);
        pushUp(root);
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        if (nums.empty() || (lower > upper))
            return 0;

        int n = nums.size();
        vector<int> sums;

        root_ = build(nums, 0, n - 1, sums);
        sort(sums.begin(), sums.end());
        auto iter1 = lower_bound(sums.begin(), sums.end(), lower);
        auto iter2 = upper_bound(sums.begin(), sums.end(), upper);

        if (iter1 == sums.end())
            return 0;

        if (iter2 == sums.end())
            return iter2 - iter1 - 1;

        return iter2 - iter1;
    }
};