#pragma once


struct SegmentTreeNode
{
    int start_;
    int end_;
    int status_;

    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    SegmentTreeNode(int start, int end, bool status) : start_(start), end_(end), status_(status), left_(nullptr), right_(nullptr)
    {

    }
};

void remove(SegmentTreeNode* root)
{
    if (!root)
        return;

    remove(root->left_);
    remove(root->right_);

    delete root;
    root = nullptr;
}

bool update(SegmentTreeNode* root, int start, int end, bool status)
{
    if (start <= root->start_ && end >= root->end_)
    {
        root->status_ = status;
        remove(root->left_);
        remove(root->right_);

        return status;
    }

    if (start >= root->end_ || end <= root->start_)
        return root->status_;

    int mid = root->start_ + (root->end_ - root->start_) / 2;
    if (root->left_ == nullptr || root->right_ == nullptr)
    {
        root->left_ = new SegmentTreeNode(root->start_, mid, root->status_);
        root->right_ = new SegmentTreeNode(mid, root->end_, root->status_);
    }

    bool leftStatus = update(root->left_, start, end, status);
    bool rightStatus = update(root->right_, start, end, status);

    root->status_ = leftStatus && rightStatus;
    return root->status_;
}

bool query(SegmentTreeNode* root, int start, int end)
{
    if (start >= root->end_ || end <= root->start_)
        return true;

    if ((start <= root->start_ && end >= root->end_) || root->left_ == nullptr)
        return root->status_;

    int mid = root->start_ + (root->end_ - root->start_) / 2;
    if (end <= mid)
        return query(root->left_, start, end);
    else if (start >= mid)
        return query(root->right_, start, end);
    else
        return query(root->left_, start, end) && query(root->right_, start, end);
}

class RangeModule
{
    SegmentTreeNode* root_;

public:
    RangeModule(): root_(new SegmentTreeNode(0, 10e9, false))
    {

    }

    void addRange(int left, int right)
    {
        update(root_, left, right, true);
    }

    bool queryRange(int left, int right)
    {
        return query(root_, left, right);
    }

    void removeRange(int left, int right)
    {
        update(root_, left, right, false);
    }
};
