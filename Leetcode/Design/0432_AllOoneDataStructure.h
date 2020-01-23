#pragma once
#include <string>
#include <unordered_map>
#
using namespace std;

class AllOne
{
public:
    /** Initialize your data structure here. */
    AllOne()
    {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key)
    {
        if (m_.count(key))
        {
            m_[key]++;
        }
        else
        {
            m_[key] = 1;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key)
    {
        if (1 == m_[key])
        {
            m_.erase(key);
        }
        else
        {
            m_[key]--;
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        string res("");
        int maxValue = INT_MIN;
        for (auto iter = m_.begin(); iter != m_.end(); ++iter)
        {
            if (maxValue < iter->second)
            {
                maxValue = iter->second;
                res = iter->first;
            }

        }

        return res;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        string res("");
        int minValue = INT_MAX;
        for (auto iter = m_.begin(); iter != m_.end(); ++iter)
        {
            if (minValue > iter->second)
            {
                minValue = iter->second;
                res = iter->first;
            }
        }

        return res;
    }

private:
    unordered_map<string, int> m_;
};
