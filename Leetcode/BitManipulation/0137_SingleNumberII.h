#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

// detail explation
// https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers

class SingleNumberIISolution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int x1 = 0, x2 = 0, mask = 0;
        for (int num : nums)
        {
            x2 ^= (x1 & num);
            x1 ^= num;

            mask = ~(x2 & x1);
            x2 &= mask;
            x1 &= mask;
        }

        return x1;
    }
};
