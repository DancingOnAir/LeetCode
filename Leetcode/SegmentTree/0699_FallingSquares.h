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
    int lazy_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    SegmentTreeNode(int start, int end) : start_(start), end_(end), height_(0), lazy_(0), left_(nullptr), right_(nullptr)
    {

    }

    void updateValue(int val)
    {
        lazy_ = val;
        height_ = val;
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
        root->height_ = max(root->left_->height_, root->right_->height_);
    }

    void pushDown(SegmentTreeNode* root)
    {
        int lazy = root->lazy_;
        if (lazy)
        {
            root->left_->updateValue(lazy);
            root->right_->updateValue(lazy);
            root->lazy_ = 0;
        }
    }

    void update(SegmentTreeNode* root, int start, int end, int val)
    {
        if (!root || end < root->start_ || start > root->end_)
            return;

        if (start <= root->start_ && end >= root->end_)
        {
            root->updateValue(val);
            return;
        }

        pushDown(root);

        update(root->left_, start, end, val);
        update(root->right_, start, end, val);

        pushUp(root);
    }

    int query(SegmentTreeNode* root, int start, int end)
    {
        if (!root || start > root->end_ || end < root->start_)
            return 0;

        if (start <= root->start_ && end >= root->end_)
            return root->height_;

        pushDown(root);
        return max(query(root->left_, start, end), query(root->right_, start, end));
    }

public:
    vector<int> fallingSquares(vector<vector<int>>& positions)
    {
        set<int> s;
        for (auto& pos : positions)
        {
            s.emplace(pos[0]);
            //这里减1为了让邻接的square高度不累加
            s.emplace(pos[0] + pos[1] - 1);
        }

        unordered_map<int, int> idxs;
        int k = 0;
        for (int x : s)
            idxs[x] = k++;

        SegmentTreeNode* root = build(0, k - 1);

        vector<int> res;
        for (auto& pos : positions)
        {
            int l = idxs[pos[0]];
            int r = idxs[pos[0] + pos[1] - 1];

            int maxHeight = query(root, l, r);
            update(root, l, r, maxHeight + pos[1]);
            res.emplace_back(query(root, 0, k - 1));
        }

        return res;
    }
};