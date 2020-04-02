#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

// detail explation
// https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers

class SingleNumberIISolution
{
public:
    // without bit operation
    int singleNumber(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> m(32);
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            for (int j = 31; j >= 0; --j)
            {
                m[j] += num & 1;
                num >>= 1;

                if (!num)
                    break;
            }
        }

        int res = 0;
        for (int i = 31; i >= 0; --i)
        {
            int remainder = m[i] % 3;
            if (remainder)
                res += 1 << (31 - i);
        }

        return res;
    }


    // bit manipulation
    int singleNumber1(vector<int>& nums)
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
