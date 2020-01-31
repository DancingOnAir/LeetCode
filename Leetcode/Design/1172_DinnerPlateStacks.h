#pragma once
#include <vector>
#include <stack>

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

        if (plates_.empty())
        {
            stack<int> temp;
            temp.emplace(val);

            if (capacity_ == 1)
                plates_.emplace_back(make_pair(true, temp));
            else
                plates_.emplace_back(make_pair(false, temp));
            
            return;
        }

        for (int i = 0; i < plates_.size(); ++i)
        {
            if (plates_[i].first == false)
            {
                plates_[i].second.emplace(val);
                if (plates_[i].second.size() == capacity_)
                    plates_[i].first = true;

                return;
            }
        }

        stack<int> temp;
        temp.emplace(val);
        plates_.emplace_back(make_pair(capacity_ == 1 ? true : false, temp));

    }

    int pop()
    {
        if (capacity_ < 1 || plates_.empty())
            return -1;

        for (int i = plates_.size() - 1; i >= 0; --i)
        {
            if (!plates_[i].second.empty())
            {
                int res = plates_[i].second.top();

                plates_[i].second.pop();
                plates_[i].first = false;
                return res;
            }
        }

        return -1;
    }

    int popAtStack(int index)
    {
        if (index >= plates_.size() || plates_[index].second.empty())
            return -1;

        int res = plates_[index].second.top();
        plates_[index].second.pop();
        plates_[index].first = false;

        return res;
    }

    int getSize() const
    {
        return plates_.size();
    }

private:
    int capacity_;

    // pair: 1->is full = true, 2-> stack for value
    vector<pair<bool, stack<int>>> plates_;
};
