#pragma once
#include <stdint.h>

class Numberof1BitsSolution
{
public:
    // explation for below bit operations
    // eg. for 2 digits
    // (ab & 0x01) + ((ab >> 1) & 0x01) = b + a
    int hammingWeight(uint32_t n)
    {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

        return n;
    }

    int hammingWeight2(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            n = n & (n - 1);
            ++res;
        }

        return res;
    }
};