#pragma once
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow2(vector<int>& nums, int k)
    {
        if (nums.empty() || k < 1 || k > nums.size())
            return vector<int>();

        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.emplace_back(i);
            if (i >= k - 1)
                res.emplace_back(nums[dq.front()]);
        }

        return res;
    }

    class MaxQueue
    {
    public:
        void pop(int num)
        {
            if (!data_.empty() && data_.front() == num)
                data_.pop_front();
        }

        void push(int num)
        {
            while (!data_.empty() && data_.back() < num)
                data_.pop_back();
            data_.emplace_back(num);
        }

        int getMax()
        {
            return data_.front();
        }

    private:
        deque<int> data_;
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.empty() || k < 1 || k > nums.size())
            return vector<int>();

        vector<int> res;
        MaxQueue mq;
        for (int i = 0; i < k - 1; ++i)
            mq.push(nums[i]);

        for (int i = k - 1; i < nums.size(); ++i)
        {
            mq.push(nums[i]);
            res.emplace_back(mq.getMax());
            mq.pop(nums[i - k + 1]);
        }

        return res;
    }
};