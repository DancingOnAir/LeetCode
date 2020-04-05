#pragma once
#include <stdint.h>
#include <vector>
using namespace std;

class ReverseBitsSolution
{
public:
    // Redis code, optimize based on the below function: reverseBits1.
    // 32 - abcd efgh ijkl mnop qrst uvwx yzAB CDEF
    // 16 - qrst uvwx yzAB CDEF abcd efgh ijkl mnop
    // 08 - yzAB CDEF qrst uvwx ijkl mnop abcd efgh
    // 04 - CDEF yzAB uvwx qrst mnop ijkl efgh abcd
    // 02 - EFCD AByz wxuv stqr opmn klij ghef cdab
    // 01 - FEDC BAzy xwvu tsrq ponm lkji hgfe dcba
    uint32_t reverseBits(uint32_t n)
    {
        unsigned int s = 8 * sizeof(n);
        uint32_t mask = ~0;

        while ((s >>= 1) > 0)
        {
            mask ^= mask << s;
            n = ((n >> s) & mask) | ((n << s) & ~mask);
        }

        return n;
    }

    // for 8 bit binary number abcdefgh, the process is as follow:
    // abcdefgh->efghabcd->ghefcdab->hgfedcba
    uint32_t reverseBits1(uint32_t n)
    {
        n = (n << 16) | (n >> 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

        return n;
    }

    uint32_t reverseBits2(uint32_t n)
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
