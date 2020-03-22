#pragma once
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct stNode
{
    int start_;
    int end_;
    int length_;
    // val, count
    unordered_map<int, int> frequency_;

    stNode* left_;
    stNode* right_;

    stNode(int start, int end)
        : start_(start), end_(end), length_(end - start + 1), left_(nullptr), right_(nullptr)
    {

    }

    void initFrequency(int val)
    {
        frequency_[val]++;
    }
};

unordered_map<int, int> mergeFrequency(unordered_map<int, int>& lhs, unordered_map<int, int>& rhs)
{
    for (auto iter = rhs.begin(); iter != rhs.end(); ++iter)
    {
        lhs[iter->first] += iter->second;
    }

    return lhs;
}

void pushUpSegmentTree(stNode* root)
{
    mergeFrequency(root->frequency_, root->left_->frequency_);
    mergeFrequency(root->frequency_, root->right_->frequency_);
}

stNode* buildSegmentTree(const vector<int>& nums, int left, int right)
{
    if (left > right)
        return nullptr;

    auto root = new stNode(left, right);
    if (left == right)
    {
        root->initFrequency(nums[left]);
        return root;
    }

    int mid = root->start_ + ((root->end_ - root->start_) >> 1);
    root->left_ = buildSegmentTree(nums, left, mid);
    root->right_ = buildSegmentTree(nums, mid + 1, right);
    pushUpSegmentTree(root);

    return root;
}

unordered_map<int, int> querySegmentTree(stNode* root, int left, int right, int threshold)
{
    if (!root || left > root->end_ || right < root->start_)
        return { {0, -1} };

    if (left <= root->start_ && right >= root->end_)
    {
        return root->frequency_;
    }

    int mid = root->start_ + ((root->end_ - root->start_) >> 1);

    if (right <= mid)
        return querySegmentTree(root->left_, left, right, threshold);
    else if (left > mid)
        return querySegmentTree(root->right_, left, right, threshold);
    else
        return mergeFrequency(querySegmentTree(root->left_, left, right, threshold), querySegmentTree(root->right_, left, right, threshold));
}

class MajorityChecker
{
private:
    stNode* root_;
public:
    MajorityChecker(vector<int>& arr)
    {
        root_ = buildSegmentTree(arr, 0, arr.size() - 1);
    }

    int query(int left, int right, int threshold)
    {
        if (threshold > right - left + 1)
            return -1;

        auto res = querySegmentTree(root_, left, right, threshold);
        for (auto iter : res)
        {
            if (iter.second >= threshold)
                return iter.first;
        }

        return -1;
    }
};
