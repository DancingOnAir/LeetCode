#pragma once
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache
{
public:
    LFUCache(int capacity): capacity_(capacity)
    {

    }

    int get(int key)
    {
        if (capacity_ <= 0 || !m_.count(key))
            return -1;

        increaseFrequency(key);

        return m_[key].second->second;
    }

    void put(int key, int value)
    {
        if (capacity_ <= 0)
            return;

        if (m_.count(key))
        {
            increaseFrequency(key);
            m_[key].second->second = value;
            return;
        }

        if (m_.size() >= capacity_)
        {
            auto LFUkv = matrix_.back().kvs_.back();

            matrix_.back().kvs_.pop_back();
            if (matrix_.back().kvs_.empty())
                matrix_.pop_back();

            m_.erase(LFUkv.first);
        }

        if (matrix_.back().frequent_ == 1)
        {
            auto lastRow = prev(matrix_.end());
            lastRow->kvs_.emplace_front(make_pair(key, value));
            m_.emplace(key, make_pair(lastRow, lastRow->kvs_.begin()));
        }
        else
        {
            auto newRow = matrix_.emplace(matrix_.end(), Bucket(1, make_pair(key, value)));
            m_.emplace(key, make_pair(newRow, newRow->kvs_.begin()));
        }
    }


private:
    void increaseFrequency(int key)
    {
        auto row = m_[key].first;
        auto col = m_[key].second;
        auto prevRow = prev(row);

        if (prevRow == matrix_.end() || prevRow->frequent_ != row->frequent_ + 1)
        {
            auto newRow = matrix_.emplace(row, Bucket(row->frequent_ + 1, make_pair(key, col->second)));
            m_[key] = make_pair(newRow, newRow->kvs_.begin());
        }
        else
        {
            prevRow->kvs_.emplace_front(make_pair(key, col->second));
            m_[key] = make_pair(prevRow, prevRow->kvs_.begin());

        }

        row->kvs_.erase(col);
        if (row->kvs_.empty())
            matrix_.erase(row);
    }

    struct Bucket
    {
        int frequent_;
        list<pair<int, int>> kvs_;
        Bucket(int frequent, pair<int, int> kv) : frequent_(frequent), kvs_({ kv })
        {

        }
    };

    int capacity_;
    list<Bucket> matrix_;
    unordered_map<int, pair<list<Bucket>::iterator, list<pair<int, int>>::iterator>> m_;
};
