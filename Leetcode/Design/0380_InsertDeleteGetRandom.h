#pragma once

#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m_.count(val))
            return false;

        v_.emplace_back(val);
        m_[val] = v_.size() - 1;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (!m_.count(val))
            return false;

        int last = v_.back();
        m_[last] = m_[val];
        v_[m_[val]] = last;

        m_.erase(val);
        v_.pop_back();

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return v_[(rand() % v_.size())];
    }

private:
    std::unordered_map<int, int> m_;
    std::vector<int> v_;
};