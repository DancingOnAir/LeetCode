#pragma once

struct MyListNode
{
    int val_;
    MyListNode* next_;
    MyListNode(int val): val_(val), next_(nullptr) {}
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    MyLinkedList(): head_(nullptr)
    {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        auto temp = head_;
        while (temp && index >= 0)
        {
            if (index == 0)
                return temp->val_;

            --index;
            temp = temp->next_;
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        if (!head_)
        {
            head_ = new MyListNode(val);
            return;
        }

        MyListNode* p = new MyListNode(val);
        p->next_ = head_;
        head_ = p;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (!head_)
        {
            head_ = new MyListNode(val);
            return;
        }
        
        MyListNode* cur = head_;
        MyListNode* pre = nullptr;
        while (cur)
        {
            pre = cur;
            cur = cur->next_;
        }

        pre->next_ = new MyListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        MyListNode preHead = MyListNode(-1);
        preHead.next_ = head_;
        MyListNode* p = &preHead;

        while (p && index > 0)
        {
            --index;
            p = p->next_;
        }

        if (index == 0)
        {
            auto next = p->next_;
            p->next_ = new MyListNode(val);
            p->next_->next_ = next;

            head_ = preHead.next_;
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        MyListNode preHead = MyListNode(-1);
        preHead.next_ = head_;
        MyListNode* p = &preHead;

        while (p && index > 0)
        {
            --index;
            p = p->next_;
        }

        if (index == 0 && p->next_)
        {
            auto toBeDelete = p->next_;
            p->next_ = toBeDelete->next_;

            delete toBeDelete;

            head_ = preHead.next_;
        }

    }

private:
    MyListNode* head_;
};