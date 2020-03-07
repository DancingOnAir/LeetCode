#pragma once
#include <vector>
using namespace std;

class NumArray
{
private:
    struct stNode
    {
        int left_;
        int right_;
        int len_;
        int idx_;
        int lazy_;
        int sum_;

        void reset(int idx, int left, int right)
        {
            idx_ = idx;
            left_ = left;
            right_ = right;
            len_ = right_ - left_ + 1;
            sum_ = lazy_ = 0;
        }

        int leftChildIdx()
        {
            return idx_ << 1;
        }

        int rightChildIdx()
        {
            return idx_ << 1 | 1;
        }

        void updateByValue(int val)
        {
            lazy_ += val;
            sum_ = val * len_;
        }
    };

    vector<int> nums_;
    vector<stNode> segTree;

    void pushUp(int idx)
    {
        segTree[idx].sum_ = segTree[idx << 1].sum_ + segTree[idx << 1 | 1].sum_;
    }

    void pushDown(int idx)
    {
        int lazy = segTree[idx].lazy_;
        if (lazy)
        {
            segTree[idx << 1].updateByValue(lazy);
            segTree[idx << 1 | 1].updateByValue(lazy);
            segTree[idx].lazy_ = 0;
        }
    }

    void buildSegmentTree(int idx, int start, int end)
    {
        if (start > end)
            return;

        segTree[idx].reset(idx, start, end);
        if (start == end)
        {
            segTree[idx].sum_ = nums_[start];
            return;
        }

        int mid = (start + end) >> 1;
        buildSegmentTree(idx << 1, start, mid);
        buildSegmentTree(idx << 1 | 1, mid + 1, end);
        pushUp(idx);
    }

    bool isIntersected(int start, int end, int x, int y)
    {
        if (y < start || x > end)
            return false;
        return true;
    }

    bool isContained(int start, int end, int x, int y)
    {
        if (x <= start && y >= end)
            return true;
        return false;
    }

    void updateSegmentTree(int idx, int start, int end, int x, int y, int val)
    {
        if (!isIntersected(start, end, x, y))
            return;

        if (isContained(start, end, x, y))
        {
            segTree[idx].updateByValue(val);
            return;
        }

        pushDown(idx);

        int mid = (start + end) >> 1;
        updateSegmentTree(idx << 1, start, mid, x, y, val);
        updateSegmentTree(idx << 1 | 1, mid + 1, end, x, y, val);

        pushUp(idx);
    }

    void mergeQuery(int& sum, int idx)
    {
        sum += segTree[idx].sum_;
    }

    void query(int idx, int start, int end, int x, int y, int& sum)
    {
        if (!isIntersected(start, end, x, y))
            return;

        if (isContained(start, end, x, y))
        {
            mergeQuery(sum, idx);
            return;
        }
        pushDown(idx);

        int mid = (start + end) >> 1;
        query(idx << 1, start, mid, x, y, sum);
        query(idx << 1 | 1, mid + 1, end, x, y, sum);

        pushUp(idx);
    }

    int len_;
public:
    NumArray(vector<int>& nums)
    {
        len_ = nums.size();
        nums_.emplace_back(0);
        nums_.insert(nums_.end(), nums.begin(), nums.end());

        segTree.resize(4 * len_);

        buildSegmentTree(1, 1, len_);
    }

    void update(int i, int val)
    {
        if (i > len_)
            return;

        updateSegmentTree(1, 1, len_, i + 1, i + 1, val);
    }

    int sumRange(int i, int j)
    {
        if (j > len_ || j < i)
            return 0;

        int sum = 0;
        query(1, 1, len_, i + 1, j + 1, sum);

        return sum;
    }
};
