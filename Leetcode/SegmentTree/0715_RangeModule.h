#pragma once
#include <map>
#include <queue>

using namespace std;

// failed segment tree solution
//struct SegmentTreeNode
//{
//    int start_;
//    int end_;
//    int sum_;
//    int lazy_;
//
//    SegmentTreeNode* left_;
//    SegmentTreeNode* right_;
//    SegmentTreeNode(int start, int end, int sum) : start_(start), end_(end), sum_(sum), lazy_(0), left_(nullptr), right_(nullptr)
//    {
//
//    }
//};
//
//void pushDown(SegmentTreeNode* root)
//{
//    int lazy = root->lazy_;
//    if (lazy)
//    {
//        root->lazy_ = 0;
//        root->left_->lazy_ = 1;
//        root->right_->lazy_ = 1;
//        if (root->sum_ == 0)
//        {
//            root->left_->sum_ = 0;
//            root->right_->sum_ = 0;
//        }
//        else
//        {
//            root->left_->sum_ = root->left_->end_ - root->left_->start_ + 1;
//            root->right_->sum_ = root->right_->end_ - root->right_->start_ + 1;
//        }
//    }
//}
//
//void pushUp(SegmentTreeNode* root)
//{
//    root->sum_ = root->left_->sum_ + root->right_->sum_;
//}
//
//void update(SegmentTreeNode* root, int left, int right, bool remove)
//{
//    if (left > right)
//        return;
//
//    if (left <= root->start_ && right >= root->end_)
//    {
//        root->lazy_ = 1;
//        root->sum_ = remove ? 0 : right - left + 1;
//        return;
//    }
//
//    int mid = root->start_ + (root->end_ - root->start_) / 2;
//    if (root->left_ == nullptr)
//        root->left_ = new SegmentTreeNode(root->start_, mid, 0);
//
//    if (root->right_ == nullptr)
//        root->right_ = new SegmentTreeNode(mid + 1, root->end_, 0);
//
//    pushDown(root);
//    if (mid >= right)
//        update(root->left_, left, right, remove);
//    else if (mid <= left)
//        update(root->right_, left, right, remove);
//    else
//    {
//        update(root->left_, left, mid, remove);
//        update(root->right_, mid + 1, right, remove);
//    }
//
//    pushUp(root);
//}
//
//int query(SegmentTreeNode* root, int left, int right)
//{
//    if (left > right)
//        return 0;
//
//    if (left <= root->start_ && right >= root->end_)
//        return root->sum_;
//
//    int mid = root->start_ + (root->end_ - root->start_) / 2;
//    if (root->left_ == nullptr)
//        root->left_ = new SegmentTreeNode(root->start_, mid, 0);
//    if (root->right_ == nullptr)
//        root->right_ = new SegmentTreeNode(mid + 1, root->end_, 0);
//
//    pushDown(root);
//
//    if (mid >= right)
//        return query(root->left_, left, right);
//    else if (mid <= left)
//        return query(root->right_, left, right);
//    else
//        return query(root->left_, left, mid) + query(root->right_, mid + 1, right);
//}
//
//class RangeModule
//{
//private:
//    SegmentTreeNode* root_;
//public:
//    RangeModule(): root_(new SegmentTreeNode(0, 1e9, 0))
//    {
//
//    }
//
//    void addRange(int left, int right)
//    {
//        update(root_, left, right - 1, 0);
//    }
//
//    bool queryRange(int left, int right)
//    {
//        return query(root_, left, right - 1) == right - left;
//    }
//
//    void removeRange(int left, int right)
//    {
//        update(root_, left, right - 1, 1);
//    }
//};

class RangeModule
{
private:
    // key: right, val: left
    map<int, int> intervals;
    queue<map<int, int>::iterator> q;

public:
    RangeModule()
    {

    }

    void addRange(int left, int right)
    {
        for (auto iter = intervals.lower_bound(left); iter != intervals.end() && iter->second <= right; ++iter)
            q.emplace(iter);

        while (!q.empty())
        {
            auto iter = q.front();
            q.pop();

            left = min(left, iter->second);
            right = max(right, iter->first);
            intervals.erase(iter);
        }

        intervals.emplace(make_pair(right, left));
    }

    bool queryRange(int left, int right)
    {
        auto iter = intervals.lower_bound(right);
        return (iter != intervals.end()) && (iter->second <= left);
    }

    void removeRange(int left, int right)
    {
        for (auto iter = intervals.upper_bound(left); iter != intervals.end() && iter->second < right; ++iter)
            q.emplace(iter);

        while (!q.empty())
        {
            auto iter = q.front();
            q.pop();

            int oldRight = iter->first;
            int oldLeft = iter->second;
            intervals.erase(iter);

            if (oldLeft < left)
                intervals.emplace(make_pair(left, oldLeft));

            if (oldRight > right)
                intervals.emplace(make_pair(oldRight, right));
        }
    }
};
