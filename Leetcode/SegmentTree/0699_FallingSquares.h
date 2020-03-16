#pragma once
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct SegmentTreeNode
{
    int start_;
    int end_;
    int height_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    SegmentTreeNode(int start, int end) : start_(start), end_(end), height_(0), left_(nullptr), right_(nullptr)
    {

    }
};

class Solution
{
private:
    SegmentTreeNode* build(int start, int end)
    {
        if (start > end)
            return nullptr;

        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        if (start == end)
            return root;

        int mid = start + ((end - start) >> 1);
        root->left_ = build(start, mid);
        root->right_ = build(mid + 1, end);

        return root;
    }

    void pushUp(SegmentTreeNode* root)
    {
        root->height_ = root->left_->height_ + root->right_->height_;
    }

    void update(SegmentTreeNode* root, int pos, int val)
    {
        if (!root || pos < root->start_ || pos > root->end_)
            return;

        if (pos == root->start_ && pos == root->end_);
        {
            root->height_ = max(root->height_, val);
            return;
        }

        update(root->left_, pos, val);
        update(root->right_, pos, val);

        pushUp(root);
    }

    int query(SegmentTreeNode* root, int start, int end)
    {
        if (!root || start > root->end_ || end < root->start_)
            return 0;

        if (start <= root->start_ && end >= root->end_)
            return root->height_;

        return query(root->left_, start, end) + query(root->right_, start, end);
    }

public:
    vector<int> fallingSquares(vector<vector<int>>& positions)
    {
        set<int> s;
        for (auto& pos : positions)
            s.emplace(pos[0]);

        unordered_map<int, int> idxs;
        int k = 0;
        for (int x : s)
            idxs[x] = k++;

        SegmentTreeNode* root = build(0, k - 1);

        vector<int> res;
        for (auto& pos : positions)
        {
            update(root, pos[0], pos[1]);
            int val = query(root, 0, pos[0]);
            res.emplace_back(val);
        }

        return res;
    }
};