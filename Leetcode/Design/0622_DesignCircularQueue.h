#pragma once

struct MyQueueNode
{
    int val_;
    MyQueueNode* next_;
    MyQueueNode(int val) : val_(val), next_(nullptr)
    {

    }
};

class MyCircularQueue
{
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): capacity_(k), size_(0), head_(nullptr), tail_(nullptr)
    {

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (isFull())
            return false;

        auto newNode = new MyQueueNode(value);
        ++size_;

        if (!tail_)
        {
            head_ = tail_ = newNode;
            return true;
        }

        tail_->next_ = newNode;
        tail_ = newNode;

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (isEmpty())
            return false;

        auto toBeDelete = head_;
        head_ = head_->next_;

        if (size_ == 1)
        {
            tail_ = head_;
        }

        delete toBeDelete;
        toBeDelete = nullptr;

        --size_;

        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (isEmpty())
            return -1;
        return head_->val_;
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (isEmpty())
            return -1;
        return tail_->val_;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return size_ == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return size_ >= capacity_;
    }

private:
    int capacity_;
    int size_;
    MyQueueNode* head_;
    MyQueueNode* tail_;
};