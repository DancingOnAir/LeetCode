#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    bool isSubstring(const string& lhs, const string& rhs)
    {
        if (lhs.empty() || rhs.empty())
            return true;

        if (lhs.size() > rhs.size())
            return isSubstring(rhs, lhs);

        int i = 0, j = 0;
        while (i < lhs.size() && j < rhs.size())
        {
            while (j < rhs.size() && lhs[i] != rhs[j])
            {
                ++j;
            }

            if (j < rhs.size())
            {
                ++i;
                ++j;
            }
        }

        return i == lhs.size();
    }

    int findLUSlength(vector<string>& strs)
    {
        map<int, vector<pair<string, bool>>, greater<int>> counts;
        for (auto& str : strs)
        {
            counts[str.size()].emplace_back(make_pair(str, false));
        }

        for (auto iter = counts.begin(); iter != counts.end(); ++iter)
        {
            for (int i = 0; i < iter->second.size(); ++i)
            {
                if (iter->second[i].second)
                    continue;

                for (int j = i + 1; j < iter->second.size(); ++j)
                {
                    if (iter->second[j].second)
                        continue;

                    if (iter->second[i].first == iter->second[j].first)
                    {
                        iter->second[i].second = true;
                        iter->second[j].second = true;
                    }
                }

            }

            for (int i = 0; i < iter->second.size(); ++i)
            {
                if (iter->second[i].second)
                    continue;

                for (auto j = counts.begin(); j != iter; ++j)
                {
                    for (auto& p : j->second)
                    {
                        if (isSubstring(iter->second[i].first, p.first))
                        {
                            iter->second[i].second = true;
                        }
                    }
                }

                if (iter->second[i].second == false)
                    return iter->first;
            }
        }

        return -1;
    }

};