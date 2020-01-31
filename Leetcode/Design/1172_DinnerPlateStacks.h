#pragma once
#include <vector>
#include <stack>
#include <map>
#include <queue>
using namespace std;

class DinnerPlates
{
public:
    DinnerPlates(int capacity): capacity_(capacity)
    {

    }

    void push(int val)
    {
        if (capacity_ < 1)
            return;

        if (available_.empty())
            available_.emplace(m_.size());

        m_[*available_.begin()].emplace_back(val);

        if (m_[*available_.begin()].size() == capacity_)
            available_.erase(available_.begin());
    }

    int pop()
    {
        if (capacity_ < 1 || m_.empty())
            return -1;

        return popAtStack(m_.rbegin()->first);
    }

    int popAtStack(int index)
    {
        if (!m_.count(index) || m_[index].empty())
            return -1;

        int res = m_[index].back();
        m_[index].pop_back();
        available_.emplace(index);
        if (m_[index].empty())
            m_.erase(index);

        return res;
    }

    int getSize() const
    {
        return m_.size();
    }

private:
    int capacity_;
    map<int, vector<int>> m_;
    set<int> available_;
};
