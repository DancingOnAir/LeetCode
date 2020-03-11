#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> res_;

public:
    struct SegmentTreeNode
    {
        int start_;
        int end_;
        int count_;
        //int val_;
        SegmentTreeNode* left_;
        SegmentTreeNode* right_;
        SegmentTreeNode(int start, int end) : start_(start), end_(end), count_(0), left_(nullptr), right_(nullptr)
        {

        }
    };

    SegmentTreeNode* buildSegmentTree(int start, int end)
    {
        if (start > end)
            return nullptr;

        if (start == end)
        {
            return new SegmentTreeNode(start, end);
        }

        int mid = start + ((end - start) >> 1);
        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        root->left_ = buildSegmentTree(start, mid);
        root->right_ = buildSegmentTree(mid + 1, end);

        return root;
    }

    void updateSegmentTree(SegmentTreeNode* root, int pos)
    {
        if (!root)
            return;

        if (root->start_ == pos && root->end_ == pos)
        {
            root->count_ += 1;
            return;
        }
        else if (root->start_ <= pos && root->end_ >= pos)
        {
            updateSegmentTree(root->left_, pos);
            updateSegmentTree(root->right_, pos);

            root->count_ = root->left_->count_ + root->right_->count_;
        }
    }

    int querySegmentTree(SegmentTreeNode* root, int start, int end)
    {
        if (!root || start > root->end_ || end < root->start_)
            return 0;

        // end should greater than root->end_, cantnot equal
        if (start <= root->start_ && end > root->end_)
            return root->count_;

        return querySegmentTree(root->left_, start, end) + querySegmentTree(root->right_, start, end);
    }

    vector<int> countSmaller(vector<int>& nums)
    {
        if (nums.empty())
            return {};

        int n = nums.size();
        if (1 == n)
            return { 0 };

        vector<int> res;
        int minVal = *min_element(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for (int& num : nums)
        {
            num += abs(minVal);
        }

        int maxVal = *max_element(nums.begin(), nums.end());

        SegmentTreeNode* root = buildSegmentTree(0, maxVal);
        for (int num : nums)
        {
            int cnt = querySegmentTree(root, 0, num);
            res.emplace_back(cnt);
            updateSegmentTree(root, num);
        }
        reverse(res.begin(), res.end());

        return res;
    }

    //merge sort method
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
                res_[nums[i][1]] += j - mid - 1;
                sortNums.emplace_back(nums[i++]);
            }
            else
            {
                sortNums.emplace_back(nums[j++]);
            }
        }

        while (i <= mid)
        {
            res_[nums[i][1]] += j - mid - 1;
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
    vector<int> countSmaller1(vector<int>& nums)
    {
        if (nums.empty())
            return {};

        int n = nums.size();
        if (1 == n)
            return { 0 };

        vector<vector<int>> hold;
        for (int i = 0; i < n; ++i)
            hold.emplace_back(vector<int>({ nums[i], i }));

        res_.resize(n);

        mergeSort(hold, 0, n - 1);
        return res_;
    }

    vector<int> countSmaller2(vector<int>& nums)
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