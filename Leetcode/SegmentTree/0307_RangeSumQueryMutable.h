#pragma once
#include <vector>
using namespace std;

class NumArray
{
private:
    struct stNode
    {
        int left_;
        int right_;
        int len_;
        int idx_;
        int lazy_;
        int sum_;

        stNode(int left, int right, int len, int idx, int lazy, int sum) :
            left_(left), right_(right), len_(len), idx_(idx), lazy_(lazy), sum_(sum)
        {

        }

        void reset()
        {
            len_ = right_ - len_ + 1;
            sum_ = lazy_ = 0;
        }
    };

public:
    NumArray(vector<int>& nums)
    {

    }

    void update(int i, int val)
    {

    }

    int sumRange(int i, int j)
    {
        return 0;
    }
};
