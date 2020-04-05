#pragma once
#include <stdint.h>

class Numberof1BitsSolution
{
public:

    int hammingWeight(uint32_t n)
    {
        // eg. for 2 digits
        // ab - ((ab >> 1) & 0x01) = ab - a = 2 * a + b - a = a + b
        n -= (n >> 1) & 0x55555555;
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        // here, 4bits are enough space for calculating the number of 1 bits, but 2 bits are not enough;
        // extrme cases for 2 bits: 1111 -> 0100, for storing the num of 1bits, it needs 3 bits, not enough.
        // extrme cases for 4 bits: 1111 1111 -> 0000 1000, for storing the num of 1bits, it needs 4 bits.
        n = (n + (n >> 4)) & 0x0f0f0f0f;
        n += n >> 8;
        n += n >> 16;

        return n & 0xff; 
    }
    // explation for below bit operations
    // eg. for 2 digits
    // (ab & 0x01) + ((ab >> 1) & 0x01) = b + a
    int hammingWeight1(uint32_t n)
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