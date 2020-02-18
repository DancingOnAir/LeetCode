#pragma once
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache1
{
public:
    LFUCache1(int capacity): capacity_(capacity)
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


static const auto fast=[]()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return nullptr;
}();

class LFUCache {
public:

    int n;
    int minFreq;
    //            freq      keys
    unordered_map<int, list<int>>frequency_map;
    //            key       val       freq         keys*
    unordered_map<int, pair<int, pair<int, list<int>::iterator>>> p_map;

    void increaseFreqCount(int key)
    {
        int count = ++(p_map[key].second.first);
        auto it = p_map[key].second.second;

        frequency_map[count - 1].erase(it);
        if (frequency_map[count - 1].size() == 0)
        {
            frequency_map.erase(count - 1);
            if (count - 1 == minFreq)
                minFreq = count;
        }

        frequency_map[count].emplace_back(key);
        p_map[key].second.second = prev(frequency_map[count].end());
    }

    LFUCache(int capacity)
    {
        n = capacity;
        frequency_map.erase(frequency_map.begin(), frequency_map.end());
        p_map.erase(p_map.begin(), p_map.end());
    }

    int get(int key)
    {
        int ans;
        int count;
        list<int>::iterator it;

        if (n == 0 || (p_map.find(key) == p_map.end()))
            return -1;

        ans = p_map[key].first;
        increaseFreqCount(key);
        return ans;
    }

    void put(int key, int value)
    {
        int size = p_map.size();

        if (n == 0)
            return;

        if (p_map.find(key) == p_map.end())
        {
            if (p_map.size() == n)
            {
                p_map.erase(frequency_map[minFreq].front());
                frequency_map[minFreq].pop_front();
            }
            frequency_map[1].emplace_back(key);
            p_map[key] = { value, {1, prev(frequency_map[1].end())} };
            minFreq = 1;
        }
        else
        {
            p_map[key].first = value;
            increaseFreqCount(key);
        }
        return;
    }
};
