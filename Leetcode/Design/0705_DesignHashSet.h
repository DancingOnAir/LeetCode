#pragma once
#include <vector>
using namespace std;

class MyHashSet
{
public:
    /** Initialize your data structure here. */
    MyHashSet() : p(199)
    {
        hashset_.resize(p);
    }

    void add(int key)
    {
        if (contains(key))
            return;

        int remainder = key % p;
        hashset_[remainder].emplace_back(key);
    }

    void remove(int key)
    {
        int remainder = key % p;
        if (hashset_[remainder].empty())
            return;

        auto iter = find(hashset_[remainder].begin(), hashset_[remainder].end(), key);
        if (iter == hashset_[remainder].end())
            return;

        hashset_[remainder].erase(iter);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int remainder = key % p;
        auto temp = hashset_[remainder];
        if (temp.empty() || find(temp.begin(), temp.end(), key) == temp.end())
            return false;

        return true;
    }

private:
    int p;
    vector<vector<int>> hashset_;
};