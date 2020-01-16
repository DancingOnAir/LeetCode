#pragma once
#include <vector>
#include <map>
#include <numeric>
#include <memory>
#include <algorithm>
#include <set>

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder(): lowMedian_(nums_.end()), highMedian_(nums_.end())
    {
    }

    void addNum(int num)
    {
        auto n = nums_.size();
        nums_.emplace(num);

        if (!n)
        {
            lowMedian_ = highMedian_ = nums_.begin();
        }
        else if (n & 1)
        {
            if (num < *lowMedian_)
                --lowMedian_;
            else
                ++highMedian_;
        }
        else
        {
            if (num <= *lowMedian_)
                lowMedian_ = --highMedian_;
            else if (num >= *highMedian_)
                ++lowMedian_;
            else
                ++lowMedian_, --highMedian_;
        }
    }

    double findMedian()
    {
        return (*lowMedian_ + *highMedian_) * 0.5;
    }

private:
    std::multiset<int> nums_;
    std::multiset<int>::iterator lowMedian_, highMedian_;
};
