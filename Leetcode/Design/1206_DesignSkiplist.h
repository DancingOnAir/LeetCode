#pragma once

#include <set>
#include <vector>
using namespace std;

struct Node
{
    int val_;
    Node* right_;
    Node* down_;

    Node(): Node(0, nullptr, nullptr){}
    Node(int val, Node* right, Node* down): val_(val), right_(right), down_(down){}
};

class Skiplist
{
public:
    Skiplist(): head_(new Node()), level_(0)
    {
        srand(time(nullptr));
    }

    bool search(int target)
    {
        return find(target);
    }

    void add(int num)
    {
        int want = 1;
        for (; want <= level_ && (rand() & 1); ++want)
            ;

        if (want > level_)
        {
            ++level_;
            head_ = new Node(0, nullptr, head_);
        }

        Node* temp = head_;
        Node* last = nullptr;

        for (int i = level_; i > 0; --i)
        {
            for (; temp->right_ && temp->right_->val_ < num; temp = temp->right_)
                ;

            if (i <= want)
            {
                temp->right_ = new Node(num, temp->right_, nullptr);
                if (last)
                {
                    last->down_ = temp->right_;
                }

                last = temp->right_;
            }

            temp = temp->down_;
        }
    }

    bool erase(int num)
    {
        auto temp = find(num);
        if (!temp)
            return false;

        for (auto del = temp->right_; del; )
        {
            for (; temp->right_ != del; temp = temp->right_)
                ;

            auto t = del;
            temp->right_ = del->right_;

            del = del->down_;
            temp = temp->down_;

            delete t;
        }

        return true;
    }

private:
    Node* find(int target)
    {
        Node* res = nullptr;
        for (auto temp = head_; res == nullptr && temp; temp = temp->down_)
        {
            for (; temp->right_ && temp->right_->val_ < target; temp = temp->right_)
                ;

            if (temp->right_ && temp->right_->val_ == target)
                res = temp;
        }

        return res;
    }


    Node* head_;
    int level_;
};