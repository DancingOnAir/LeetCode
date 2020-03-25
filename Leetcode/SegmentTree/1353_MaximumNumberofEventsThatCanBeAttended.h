#pragma once
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 1e5 + 5;
struct SegmentTreeNode
{
    int start_;
    int end_;
    int val_;
    //int lazy_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    SegmentTreeNode(int start, int end) : start_(start), end_(end), val_(0), left_(nullptr), right_(nullptr)
    {

    }

    //void updateVal(int val)
    //{
    //    lazy_ += val;
    //    val_ = val;
    //}
};

void pushup(SegmentTreeNode* root)
{
    root->val_ = min(root->left_->val_, root->right_->val_);
}

//void pushdown(SegmentTreeNode* root)
//{
//    int lazy = root->lazy_;
//    if (lazy)
//    {
//        root->left_->updateVal(lazy);
//        root->right_->updateVal(lazy);
//        root->lazy_ = 0;
//    }
//}

SegmentTreeNode* buildTree(int left, int right)
{
    if (left > right)
        return nullptr;

    auto root = new SegmentTreeNode(left, right);
    if (left == right)
    {
        root->val_ = left;
        return root;
    }

    int mid = left + (right - left) / 2;
    root->left_ = buildTree(left, mid);
    root->right_ = buildTree(mid + 1, right);

    pushup(root);
    return root;
}

void updateTree(SegmentTreeNode* root, int val)
{
    if (root->start_ ==  root->end_)
    {
        root->val_ = N + 1;
        return;
    }

    int mid = root->start_ + (root->end_ - root->start_) / 2;
    if (val <= mid)
        updateTree(root->left_, val);
    else
        updateTree(root->right_, val);

    pushup(root);
}

int queryTree(SegmentTreeNode* root, int left, int right)
{
    if (!root || left > root->end_ || right < root->start_)
        return 0;

    if (left <= root->start_ && right >= root->end_)
    {
        return root->val_;
    }

    int mid = root->start_ + (root->end_ - root->start_) / 2;

    if (right <= mid)
    {
        int temp = queryTree(root->left_, left, right);
        if (temp <= N)
            return temp;
    }
    else if (left > mid)
    {
        int temp = queryTree(root->right_, left, right);
        if (temp <= N)
            return temp;
    }
    else
    {
        int temp = min(queryTree(root->left_, left, right), queryTree(root->right_, left, right));
        if (temp <= N)
            return temp;
    }

    return N + 1;
}



class Solution
{
private:
    int tree[N << 2];
    int build(int root, int start, int end)
    {
        if (start == end)
            return tree[root] = start;
        else
        {
            int mid = start + (end - start) / 2;
            return tree[root] = min(build(root << 1, start, mid), build(root << 1 | 1, mid + 1, end));
        }

    }

    int update(int i, int val, int start, int end)
    {
        if (start == end)
            return tree[i] = N + 1;

        int mid = start + (end - start) / 2;
        if (val <= mid)
            return tree[i] = min(update(i << 1, val, start, mid), tree[i << 1 | 1]);
        else
            return tree[i] = min(tree[i << 1], update(i << 1 | 1, val, mid + 1, end));
    }

    int query(int i, int start, int end, int x, int y)
    {
        if (x <= start && y >= end)
            return tree[i];

        int mid = start + (end - start) / 2;
        if (x <= mid)
        {
            int temp = query(i << 1, start, mid, x, y);
            if (temp <= N)
                return temp;
        }

        if (y > mid)
        {
            int temp = query(i << 1 | 1, mid + 1, end, x, y);
            if (temp <= N)
                return temp;
        }

        return N + 1;
    }

    SegmentTreeNode* root_;
public:
    int maxEvents(vector<vector<int>>& events)
    {
        root_ = buildTree(1, N);
        sort(events.begin(), events.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[1] < rhs[1]; });
        int res = 0;
        for (auto& event : events)
        {
            int minDay = queryTree(root_, event[0], event[1]);
            if (minDay != 0 && minDay <= event[1])
            {
                ++res;
                updateTree(root_, minDay);
            }
        }

        return res;
    }


    int maxEvents1(vector<vector<int>>& events)
    {
        build(1, 1, N);
        sort(events.begin(), events.end(), [](const vector<int>& e1, const vector<int>& e2) { return e1[1] < e2[1]; });
        int res = 0;
        for (auto& event : events)
        {
            int temp = query(1, 1, N, event[0], event[1]);
            if (temp != 0 && temp <= event[1])
            {
                ++res;
                update(1, temp, 1, N);
            }
        }

        return res;
    }

    int maxEvents2(vector<vector<int>>& events)
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

};