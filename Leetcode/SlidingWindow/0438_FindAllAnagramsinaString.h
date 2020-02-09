#pragma once
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.empty())
            return vector<int>();

        int l1 = s.size();
        int l2 = p.size();

        if (l2 > l1)
            return vector<int>();

        vector<int> vp(128);
        for (char c : p)
        {
            vp[c]++;
        }

        vector<int> res;
        int left = 0, right = 0, counter = l2;

        while (right < l1)
        {
            if (vp[s[right++]]-- > 0)
                --counter;

            while (counter == 0)
            {
                if (right - left == l2)
                    res.emplace_back(left);

                if (vp[s[left++]]++ == 0)
                    ++counter;
            }
        }

        return res;
    }
};