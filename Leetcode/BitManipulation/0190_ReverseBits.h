#pragma once
#include <stdint.h>
#include <vector>
using namespace std;

class ReverseBitsSolution
{
public:
    // for 8 bit binary number abcdefgh, the process is as follow:
    // abcdefgh->efghabcd->ghefcdab->hgfedcba
    uint32_t reverseBits(uint32_t n)
    {
        n = (n << 16) | (n >> 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

        return n;
    }

    uint32_t reverseBits1(uint32_t n)
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
