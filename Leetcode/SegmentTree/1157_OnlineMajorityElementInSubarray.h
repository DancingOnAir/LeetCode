#pragma once
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct stNode
{
    int val_;
    int count_;

    stNode() : val_(0), count_(-1)
    {

    }

    stNode operator+ (const stNode& rhs) const
    {
        stNode res;
        if (val_ == rhs.val_)
        {
            res.val_ = val_;
            res.count_ = count_ + rhs.count_;
        }
        else if (count_ >= rhs.count_)
        {
            res.val_ = val_;
            res.count_ = count_ - rhs.count_;
        }
        else
        {
            res.val_ = rhs.val_;
            res.count_ = rhs.count_ - count_;
        }

        return res;
    }

    void updateStNode(int val)
    {
        val_ = val;
        count_ = 1;
    }
};

class MajorityChecker
{
private:
    int size_;
    vector<vector<int>> hash_;
    vector<stNode> tree_;

    void buildSegmentTree(vector<int>& nums, int root, int left, int right)
    {
        if (left == right)
        {
            tree_[root].updateStNode(nums[left]);
            return;
        }

        int mid = left + (right - left) / 2;
        buildSegmentTree(nums, root << 1, left, mid);
        buildSegmentTree(nums, root << 1 | 1, mid + 1, right);
        tree_[root] = tree_[root << 1] + tree_[root << 1 | 1];
    }

    stNode querySegmentTree(int root, int left, int right, int x, int y)
    {
        if (x == left && y == right)
            return tree_[root];

        int mid = left + (right - left) / 2;
        if (y <= mid)
            return querySegmentTree(root << 1, left, mid, x, y);

        if (x > mid)
            return querySegmentTree(root << 1 | 1, mid + 1, right, x, y);

        return querySegmentTree(root << 1, left, mid, x, mid) + querySegmentTree(root << 1 | 1, mid + 1, right, mid + 1, y);
    }

public:
    MajorityChecker(vector<int>& arr)
        : size_(arr.size()), hash_(20001, vector<int>()), tree_(4 * size_, stNode())
    {
        for (int i = 0; i < size_; ++i)
        {
            hash_[arr[i]].emplace_back(i);
        }

        buildSegmentTree(arr, 1, 0, size_ - 1);
    }

    int query(int left, int right, int threshold)
    {
        if (threshold > right - left + 1)
            return -1;

        auto res = querySegmentTree(1, 0, size_ - 1, left, right);
        auto l = lower_bound(hash_[res.val_].begin(), hash_[res.val_].end(), left);
        auto r = upper_bound(hash_[res.val_].begin(), hash_[res.val_].end(), right);

        if (r - l >= threshold)
            return res.val_;

        return -1;
    }
};
