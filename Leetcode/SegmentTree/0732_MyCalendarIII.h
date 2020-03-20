#pragma once
using namespace std;

struct SegmentTreeNode
{
    int start_;
    int end_;
    int sum_;
    int lazy_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    explicit SegmentTreeNode(int start, int end, int sum)
        : start_(start), end_(end), sum_(sum), lazy_(0), left_(nullptr), right_(nullptr)
    {

    }

    void updateByVal(int val)
    {
        lazy_ += val;
        sum_ += val;
    }
};

void pushDown(SegmentTreeNode* root)
{
    int lazy = root->lazy_;
    if (lazy)
    {
        root->left_->updateByVal(lazy);
        root->right_->updateByVal(lazy);
        root->lazy_ = 0;
    }
}

void pushUp(SegmentTreeNode* root)
{
    root->sum_ = max(root->left_->sum_, root->right_->sum_);
}

void update(SegmentTreeNode* root, int left, int right)
{
    if (left > root->end_ || right < root->start_)
        return;

    if (left <= root->start_ && right >= root->end_)
    {
        root->updateByVal(1);
        return;
    }

    int mid = root->start_ + ((root->end_ - root->start_) >> 1);
    if (!root->left_)
        root->left_ = new SegmentTreeNode(root->start_, mid, 0);
    if (!root->right_)
        root->right_ = new SegmentTreeNode(mid + 1, root->end_, 0);
    pushDown(root);

    if (right <= mid)
        update(root->left_, left, right);
    else if (left > mid)
        update(root->right_, left, right);
    else
    {
        update(root->left_, left, right);
        update(root->right_, left, right);
    }

    pushUp(root);
}

int query(SegmentTreeNode* root, int left, int right)
{
    if (left > root->end_ || right < root->start_)
        return 0;

    if (left <= root->start_ && right >= root->end_)
        return root->sum_;

    pushDown(root);
    int mid = root->start_ + ((root->end_ - root->start_) >> 1);
    if (!root->left_)
        root->left_ = new SegmentTreeNode(root->start_, mid, 0);
    if (!root->right_)
        root->right_ = new SegmentTreeNode(mid + 1, root->end_, 0);

    if (right <= mid)
        return query(root->left_, left, right);
    else if (left > mid)
        return query(root->right_, left, right);
    else
        return max(query(root->left_, left, right), query(root->right_, left, right));
}

class MyCalendarThree
{
private:
    SegmentTreeNode* root_;
    int maxBooking_;
public:
    MyCalendarThree(): root_(new SegmentTreeNode(0, 1e9, 0)), maxBooking_(0)
    {

    }

    int book(int start, int end)
    {
        update(root_, start, end - 1);
        maxBooking_ = max(maxBooking_, query(root_, start, end - 1));
        return maxBooking_;
    }
};
