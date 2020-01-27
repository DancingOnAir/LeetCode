#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct HashNode
{
    int key_;
    int val_;
    HashNode* next_;

    HashNode(int key, int val): key_(key), val_(val), next_(nullptr){}
};

const int factor = 199;

class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        hashmap_ = vector<HashNode*>(factor, new HashNode(-1, -1));
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int index = key % factor;
        auto iter = hashmap_[index];
        HashNode* preHead;
        while (iter)
        {
            if (iter->key_ == key)
            {
                iter->val_ = value;
                return;
            }

            preHead = iter;
            iter = iter->next_;
        }

        preHead->next_ = new HashNode(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int index = key % factor;
        HashNode* iter = hashmap_[index];

        while (iter)
        {
            if (iter->key_ == key)
                return iter->val_;

            iter = iter->next_;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int index = key % factor;
        auto iter = hashmap_[index];
        while (iter)
        {
            if (iter->key_ == key)
                iter->val_ = -1;
            iter = iter->next_;
        }

    }

private:
    vector<HashNode*> hashmap_;
};