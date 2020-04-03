#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class SingleNumberIIISolution
{
public:
    unsigned int findLastBitOfOne(int num)
    {
        int res = 0;
        while ((num & 1) == 0 && res < 8 * sizeof(int))
        {
            num >>= 1;
            ++res;
        }

        return res;
    }

    bool isBitOne(int num, unsigned int indexBitOfOne)
    {
        num >>= indexBitOfOne;

        return (num & 1);
    }

    vector<int> singleNumber(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2)
            return vector<int>();

        vector<int> res;
        int xorRes = 0;
        for (int num : nums)
            xorRes ^= num;

        auto lastIndexOfOne = findLastBitOfOne(xorRes);
        int num1 = 0;
        int num2 = 0;

        for (int i = 0; i < n; ++i)
        {
            if (isBitOne(nums[i], lastIndexOfOne))
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }

        res.emplace_back(num1);
        res.emplace_back(num2);

        return res;
    }

    vector<int> singleNumber1(vector<int>& nums)
    {
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