#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        vector<int> m(128);
        int left = 0, right = 0, res = 0, counter = 0;
        while (right < s.size())
        {
            if (m[s[right++]]++ > 0)
                ++counter;

            while (counter > 0)
            {
                if (m[s[left++]]-- > 1)
                    --counter;
            }

            res = max(res, right - left);
        }

        return res;
    }
};