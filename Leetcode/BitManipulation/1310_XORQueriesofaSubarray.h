#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        if (queries.empty())
            return vector<int>();

        vector<int> res;
        vector<int> pre(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i)
            pre[i + 1] = pre[i] ^ arr[i];

        for (auto& q : queries)
        {
            res.emplace_back(pre[q[0]] ^ pre[q[1] + 1]);
        }

        return res;
    }
};