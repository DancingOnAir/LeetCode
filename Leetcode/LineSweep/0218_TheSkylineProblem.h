#pragma once
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        if (buildings.empty())
            return vector<vector<int>>();

        vector<vector<int>> res;
        multiset<pair<int, int>> all;
        for (auto& b : buildings)
        {
            all.emplace(make_pair(b[0], -b[2]));
            all.emplace(make_pair(b[1], b[2]));
        }

        multiset<int> heights{ 0 };
        vector<int> last{ 0, 0 };

        for (auto& p : all)
        {
            if (p.second < 0)
                heights.emplace(-p.second);
            else
                heights.erase(heights.find(p.second));

            int maxHeight = *heights.rbegin();

            if (last[1] != maxHeight)
            {
                last[0] = p.first;
                last[1] = maxHeight;

                res.emplace_back(last);
            }
        }

        return res;
    }
};