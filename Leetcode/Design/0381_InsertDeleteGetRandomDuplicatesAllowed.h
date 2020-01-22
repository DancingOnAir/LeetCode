#pragma once
#include <unordered_map>
#include <vector>
#include <random>
using namespace std;

class RandomizedCollection
{
public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        m_[val].emplace_back(v_.size());
        v_.emplace_back(make_pair(val, m_[val].size() - 1));
        return m_.find(val) == m_.end();
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (!m_.count(val))
            return false;

        auto last = v_.back();
        m_[last.first][last.second] = m_[val].back();
        v_[m_[val].back()] = last;

        m_[val].pop_back();
        if (m_[val].empty())
            m_.erase(val);
        v_.pop_back();

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return v_[rand() % v_.size()].first;
    }

private:
    unordered_map<int, vector<int>> m_;
    vector<pair<int, int>> v_;
};
