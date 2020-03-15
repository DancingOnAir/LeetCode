#pragma once
#include <vector>
#include <set>
#include <unordered_map>
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
    SegmentTreeNode* buildSegmentTree(long long start, long long end)
    {
        if (start > end)
            return nullptr;

        auto root = new SegmentTreeNode(start, end);
        if (start == end)
        {
            return root;
        }

        long long mid = start + ((end - start) >> 1);
        root->left_ = buildSegmentTree(start, mid);
        root->right_ = buildSegmentTree(mid + 1, end);

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

        if (start <= root->start_ && end >= root->end_)
            return root->count_;

        return querySegmentTree(root->left_, start, end) + querySegmentTree(root->right_, start, end);
    }

public:
    int sortAndCount(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (end - begin <= 1)
            return 0;

        auto mid = begin + ((end - begin) >> 1);
        int count = sortAndCount(begin, mid) + sortAndCount(mid, end);
        for (auto i = begin, j = mid; i != mid; ++i)
        {
            while (j != end && *i > 2L * *j)
                ++j;

            count += j - mid;
        }

        inplace_merge(begin, mid, end);

        return count;
    }

    int reversePairs(vector<int>& nums)
    {
        return sortAndCount(nums.begin(), nums.end());
    }

    int reversePairs1(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        set<long long> s;
        for (int num : nums)
        {
            s.emplace(num);
            s.emplace(num * 2L + 1);
        }

        unordered_map<long long, int> idxs;
        int k = 0;
        for (long long num : s)
            idxs[num] = k++;

        SegmentTreeNode* root = buildSegmentTree(0, k - 1);
        int res = 0;
        for (int num : nums)
        {
            int idx = idxs[num * 2L + 1];
            res += querySegmentTree(root, idx, k - 1);
            updateSegmentTree(root, idxs[num]);
        }

        return res;
    }
};
