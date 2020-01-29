#pragma once

struct MyDequeNode
{
    int val_;
    MyDequeNode* next_;
    MyDequeNode* prev_;
    MyDequeNode(int val): val_(val), next_(nullptr), prev_(nullptr) {}
};

class MyCircularDeque
{
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): capacity_(k), size_(0), head_(nullptr), tail_(nullptr)
    {

    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;

        if (isEmpty())
        {
            head_ = tail_ = new MyDequeNode(value);
            ++size_;
            return true;
        }

        auto temp = new MyDequeNode(value);
        temp->next_ = head_;
        head_->prev_ = temp;
        head_ = temp;
        ++size_;

        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;

        if (isEmpty())
        {
            head_ = tail_ = new MyDequeNode(value);
            ++size_;
            return true;
        }

        auto temp = new MyDequeNode(value);
        temp->prev_ = tail_;
        tail_->next_ = temp;
        tail_ = temp;
        ++size_;

        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;

        auto toBeDelete = head_;
        if (!toBeDelete->next_)
        {
            head_ = tail_ = nullptr;

            delete toBeDelete;
            toBeDelete = nullptr;
            --size_;

            return true;
        }


        head_ = head_->next_;
        head_->prev_ = nullptr;

        delete toBeDelete;
        toBeDelete = nullptr;
        --size_;

        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;

        auto toBeDelete = tail_;
        if (!toBeDelete->prev_)
        {
            head_ = tail_ = nullptr;

            delete toBeDelete;
            toBeDelete = nullptr;
            --size_;

            return true;
        }


        tail_ = tail_->prev_;
        tail_->next_ = nullptr;

        delete toBeDelete;
        toBeDelete = nullptr;
        --size_;

        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
            return -1;

        return head_->val_;
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
            return -1;

        return tail_->val_;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return !size_;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return size_ == capacity_;
    }

private:
    MyDequeNode* head_;
    MyDequeNode* tail_;
    int size_;
    int capacity_;
};