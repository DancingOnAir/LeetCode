#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int l1 = s.size();
        int l2 = t.size();

        if (t.empty() || l2 > l1)
            return "";

        vector<int> m(128);
        for (char c : t)
            ++m[c];

        int left = 0, right = 0, counter = 0, dist = INT_MAX, start = 0;
        while (right < l1)
        {
            if (m[s[right++]]-- > 0)
                ++counter;

            while (counter == l2)
            {
                if (dist > right - left)
                {
                    dist = right - left;
                    start = left;
                }

                if (m[s[left++]]++ == 0)
                    --counter;
            }
        }

        return dist == INT_MAX ? "" : s.substr(start, dist);
    }
};