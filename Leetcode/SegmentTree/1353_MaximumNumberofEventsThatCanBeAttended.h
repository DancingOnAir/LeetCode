#pragma once
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

struct SegmentTreeNode
{
    int start_;
    int end_;
    int count_;
    int lazy_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    SegmentTreeNode(int start, int end) : start_(start), end_(end), count_(0), lazy_(0), left_(nullptr), right_(nullptr)
    {

    }

    void updateVal(int val)
    {
        lazy_ += val;
        count_ += val;
    }
};

void pushup(SegmentTreeNode* root)
{
    root->count_ = max(root->left_->count_, root->right_->count_);
}

void pushdown(SegmentTreeNode* root)
{
    int lazy = root->lazy_;
    if (lazy)
    {
        root->left_->updateVal(lazy);
        root->right_->updateVal(lazy);
        root->lazy_ = 0;
    }
}

SegmentTreeNode* build(int left, int right)
{
    if (left > right)
        return nullptr;

    auto root = new SegmentTreeNode(left, right);
    if (left == right)
        return root;

    int mid = left + (right - left) / 2;
    root->left_ = build(left, mid);
    root->right_ = build(mid + 1, right);

    return root;
}

void update(SegmentTreeNode* root, int left, int right, int val)
{
    if (!root || left > root->end_ || right < root->start_)
        return;

    if (left == root->start_ && right == root->end_)
    {
        root->updateVal(val);
        return;
    }

    pushdown(root);
    int mid = root->start_ + (root->end_ - root->start_) / 2;

    update(root->left_, left, mid, val);
    update(root->right_, mid + 1, right, val);

    pushup(root);
}

int queryTree(SegmentTreeNode* root, int left, int right)
{
    if (!root || left > root->end_ || right < root->start_)
        return 0;

    if (left <= root->start_ && right >= root->end_)
    {
        return root->count_;
    }

    pushdown(root);
    int mid = root->start_ + (root->end_ - root->start_) / 2;
    if (right <= mid)
        return queryTree(root->left_, left, mid);
    else if (left > mid)
        return queryTree(root->right_, mid + 1, right);
    else
        return queryTree(root->left_, left, mid) + queryTree(root->right_, mid + 1, right);
}

class Solution
{

public:
    int maxEvents(vector<vector<int>>& events)
    {
        sort(events.rbegin(), events.rend());
        priority_queue<int, vector<int>, greater<int>> pq;

        int res = 0, day = 0;
        while (!events.empty() || !pq.empty())
        {
            ++day;
            while (!pq.empty() && pq.top() < day)
                pq.pop();

            while (!events.empty() && events.back()[0] == day)
            {
                pq.emplace(events.back()[1]);
                events.pop_back();
            }

            if (pq.empty())
                continue;

            pq.pop();
            ++res;
        }

        return res;
    }

    int maxEvents1(vector<vector<int>>& events)
    {
        set<int> s;
        for (auto& event : events)
        {
            s.emplace(event[0]);
            s.emplace(event[1]);
        }

        unordered_map<int, int> m;
        int k = 0;
        for (int day : s)
            m[day] = k++;

        auto root = build(0, k - 1);
        for (auto& event : events)
        {
            update(root, m[event[0]], m[event[1]], 1);
        }

        return queryTree(root, 0, k - 1);
    }
};