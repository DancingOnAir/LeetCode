#pragma once
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    class MedianQueue
    {
    public:
        MedianQueue(size_t len) : len_(len)
        {

        }

        void pop(int num)
        {
            data_.erase(data_.lower_bound(num));
        }

        void push(int num)
        {
            data_.emplace(num);
        }

        double getMedian()
        {
            double m1 = *next(data_.begin(), len_ / 2);
            if (len_ & 1)
            {
                return m1;
            }

            double m2 = *next(data_.begin(), len_ / 2 - 1);
            return (m1 + m2) * 0.5;
        }

    private:
        multiset<int> data_;
        size_t len_;
    };

    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.empty())
            return vector<double>();

        vector<double> res;
        MedianQueue mq(k);
        for (int i = 0; i < k - 1; ++i)
            mq.push(nums[i]);

        for (int i = k - 1; i < nums.size(); ++i)
        {
            mq.push(nums[i]);
            res.emplace_back(mq.getMedian());
            mq.pop(nums[i - k + 1]);
        }

        return res;
    }
};