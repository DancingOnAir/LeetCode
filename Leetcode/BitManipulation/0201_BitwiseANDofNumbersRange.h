#pragma once

class BitwiseANDofNumbersRangeSolution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        return ((m ^ n) == 0)? n : (n & (~(0xffffffff >> __builtin_clz(m ^ n))));
    }

    int rangeBitwiseAnd1(int m, int n)
    {
        int res = 0;
        while (n > m)
        {
            ++res;
            n >>= 1;
            m >>= 1;
        }

        return m << res;
    }
};