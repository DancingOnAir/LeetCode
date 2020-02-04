#pragma once
#include <string>

using namespace std;

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        if (s.empty())
            return 0;

        int res = 0;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return 2;

            ++i;
            --j;
        }

        return 1;
    }
};