#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int left = 0, right = 0, counter = 0, res = 0;

        while (right < s.size())
        {
            counter += abs(s[right] - t[right]);
            ++right;

            while (counter > maxCost)
            {
                counter -= abs(s[left] - t[left]);
                ++left;
            }
            res = max(res, right - left);
        }

        return res;
    }
};