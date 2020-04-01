#pragma once
#include <vector>
using namespace std;

class SingleNumberSolution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        for (int num : nums)
            res ^= num;
        return res;
    }
};