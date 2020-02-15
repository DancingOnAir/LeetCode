#pragma once
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
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

    vector<double> medianSlidingWindow2(vector<int>& nums, int k)
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

    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.empty() || k > nums.size())
            return vector<double>();

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<double> res;
        int i = 0;
        while (i < k)
        {
            maxHeap.emplace(nums[i++]);
        }

        for (int j = 0; j < k / 2; ++j)
        {
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        }

        unordered_map<int, int> count;

        while (true)
        {
            if (k & 1)
                res.emplace_back(maxHeap.top());
            else
                res.emplace_back(static_cast<double>(maxHeap.top() + minHeap.top()) * 0.5);

            if (i == nums.size())
                break;

            int m = nums[i - k], n = nums[i++], balance = 0;
            if (m <= maxHeap.top())
            {
                --balance;
                if (m == maxHeap.top())
                    maxHeap.pop();
                else
                    ++count[m];
            }
            else
            {
                ++balance;
                if (m == minHeap.top())
                    minHeap.pop();
                else
                    ++count[m];
            }

            if (!maxHeap.empty() && n <= maxHeap.top())
            {
                ++balance;
                maxHeap.emplace(n);
            }
            else
            {
                --balance;
                minHeap.emplace(n);
            }

            if (balance < 0)
            {
                maxHeap.emplace(minHeap.top());
                minHeap.pop();
            }
            else if (balance > 0)
            {
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
            }

            while (!maxHeap.empty() && count[maxHeap.top()])
            {
                --count[maxHeap.top()];
                maxHeap.pop();
            }

            while (!minHeap.empty() && count[minHeap.top()])
            {
                --count[minHeap.top()];
                minHeap.pop();
            }
        }

        return res;
    }
};