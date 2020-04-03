#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class SingleNumberIIISolution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        //int res = 0;
        //for (int num : nums)
        //    res ^= num;


        //return vector<int>();

        int n = nums.size();
        if (n < 2)
            return vector<int>();

        unordered_map<int, int> m;
        vector<int> res;
        for (int num : nums)
        {
            if (m.count(num))
                m.erase(num);
            else
                m[num]++;
        }

        res.emplace_back(m.begin()->first);
        res.emplace_back(next(m.begin())->first);

        return res;
    }
};