#pragma once
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

struct Row
{
    int val;
    list<string> keys;

    Row(int x, const string& s) : val(x), keys({ s })
    {

    }
};

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
            auto row = m_[key].first;
            auto col = m_[key].second;
            auto prevRow = prev(row);

            if (prevRow == matrix_.end() || prevRow->val != row->val + 1)
            {
                auto iter = matrix_.emplace(row, Row(row->val + 1, key));
                m_[key] = make_pair(iter, iter->keys.begin());
            }
            else
            {
                prevRow->keys.emplace_front(key);
                m_[key] = make_pair(prevRow, prevRow->keys.begin());
            }

            row->keys.erase(col);
            if (row->keys.empty())
                matrix_.erase(row);
        }
        else
        {
            if (matrix_.empty() || matrix_.back().val != 1)
            {
                auto iter = matrix_.emplace(matrix_.end(), Row(1, key));
                m_[key] = make_pair(iter, iter->keys.begin());
            }
            else
            {
                auto iter = std::prev(matrix_.end());
                iter->keys.emplace_front(key);
                m_[key] = make_pair(iter, iter->keys.begin());
            }
        }

    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key)
    {
        if (!m_.count(key))
            return;

        auto row = m_[key].first;
        auto col = m_[key].second;

        if (row->val == 1)
        {
            row->keys.erase(col);
            if (row->keys.empty())
                matrix_.erase(row);

            m_.erase(key);
            return;
        }

        auto nextRow = next(row);
        if (nextRow == matrix_.end() || nextRow->val + 1 != row->val)
        {
            auto iter = matrix_.emplace(nextRow, Row(row->val - 1, key));
            m_[key] = make_pair(iter, iter->keys.begin());
        }
        else
        {
            nextRow->keys.emplace_front(key);
            m_[key] = make_pair(nextRow, nextRow->keys.begin());
        }

        row->keys.erase(col);
        if (row->keys.empty())
            matrix_.erase(row);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        return matrix_.empty() ? "" : matrix_.front().keys.front();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        return matrix_.empty() ? "" : matrix_.back().keys.front();
    }

private:
    list<Row> matrix_;
    unordered_map<string, pair<list<Row>::iterator, list<string>::iterator>> m_;
};
