#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
using namespace std;

class Solution
{
public:
    bool isSubstring(const string& lhs, const string& rhs)
    {
        if (lhs.size() > rhs.size())
            return false;

        int i = 0;
        for (char c : rhs)
        {
            if (i < lhs.size() && c == lhs[i])
                ++i;
        }

        return i == lhs.size();
    }

    int findLUSlength(vector<string>& strs)
    {
        if (strs.empty())
            return -1;

        int res = -1;
        for (auto i = 0; i < strs.size(); ++i)
        {
            int j = 0;
            for (; j < strs.size(); ++j)
            {
                if (i == j)
                    continue;

                if (isSubstring(strs[i], strs[j]))
                    break;
            }

            if (j == strs.size())
                res = max(res, static_cast<int>(strs[i].size()));
        }

        return res;
    }

};