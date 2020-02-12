#pragma once
#include <string>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.empty() || s2.empty())
            return false;

        int l1 = s1.size();
        int l2 = s2.size();
        if (l2 < l1)
            return false;

        vector<int> m(128);
        for (char c : s1)
            m[c]++;

        int left = 0, right = 0, counter = 0;
        while (right < l2)
        {
            if (m[s2[right++]]-- > 0)
                ++counter;

            while (counter == l1)
            {
                if (right - left == l1)
                    return true;

                if (m[s2[left++]]++ == 0)
                    --counter;
            }
        }

        return false;
    }
};