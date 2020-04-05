#pragma once
#include <stdint.h>

class Numberof1BitsSolution
{
public:
    int hammingWeight(uint32_t n)
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