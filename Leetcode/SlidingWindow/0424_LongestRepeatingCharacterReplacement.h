#pragma once
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int characterReplacement2(string s, int k)
    {
        if (s.empty())
            return 0;

        int n = s.size();
        if (k >= n)
            return n;

        int res = 0;
        int left = 0, right = 0, counter = 0, maxCharCount = 0;
        vector<int> m(128);

        while (right < s.size())
        {
            m[s[right]]++;
            if (maxCharCount < m[s[right]])
            {
                maxCharCount = m[s[right]];
            }
            ++right;

            while (right - left - maxCharCount > k)
            {
                m[s[left++]]--;
                maxCharCount = *max_element(m.begin(), m.end());
            }

            res = max(res, right - left);
        }

        return res;
    }

    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0, count[91] = {};
        while (right < s.size())
        {
            count[s[right++]]++;
            if (right - left - *max_element(count + 65, count + 91) > k)
                count[s[left++]]--;
        }

        return right - left;
    }
};