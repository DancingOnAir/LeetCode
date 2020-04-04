#pragma once
#include <stdint.h>
#include <vector>
using namespace std;

class ReverseBitsSolution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        vector<int> digits(32);
        for (int i = 31; i >= 0; --i)
        {
            digits[i] = n & 0x01;
            n >>= 1;
        }

        unsigned int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (digits[i])
                res += digits[i] << i;
        }

        return res;
    }
};
