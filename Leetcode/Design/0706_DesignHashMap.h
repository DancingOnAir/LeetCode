#pragma once
#include <iostream>
#include <vector>
using namespace std;

const int factor = 199;

struct HashNode
{
    int key_;
    int val_;
    HashNode* next_;

    HashNode(int key, int val): key_(key), val_(val), next_(nullptr){}
};

class MyHashMap1
{
public:
    /** Initialize your data structure here. */
    MyHashMap1()
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

#include <forward_list>

class MyHashMap
{
public:

    /** Initialize your data structure here. */
    MyHashMap(): buckets_(factor)
    {

    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        auto& bucket = buckets_[GetBucketIndex(key)];
        for (auto& temp : bucket)
        {
            if (temp.first == key)
            {
                temp.second = value;
                return;
            }
        }

        bucket.emplace_front(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        auto& bucket = buckets_[GetBucketIndex(key)];
        for (const auto& temp : bucket)
        {
            if (temp.first == key)
                return temp.second;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        auto& bucket = buckets_[GetBucketIndex(key)];
        bucket.remove_if([key](auto temp) { return temp.first == key; });
    }

private:
    size_t GetBucketIndex(int key)
    {
        return key % factor;
    }

    using Bucket = forward_list<pair<int, int>>;
    vector<Bucket> buckets_;
};