#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    std::set<int> inputs(nums.begin(), nums.end());
    int maxLen = 0, curLen = 0;
    for (auto& x : inputs)
    {
        if (inputs.find(x - 1) == inputs.end())
        {
            int y = x + 1;
            while (inputs.find(y) != inputs.end())
                ++y;

            maxLen = max(maxLen, y - x);
        }
    }

    return maxLen;
}

int longestConsecutive2(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int result = 0;
    std::unordered_map<int, int> m;
    for (auto& x : nums)
    {
        if (m[x])
            continue;

        if (m.find(x + 1) == m.end() && m.find(x - 1) == m.end())
        {
            result = max(result, m[x] = 1);
            continue;
        }


        if (m.find(x - 1) == m.end())
        {
            m[x] = m[x + m[x + 1]] = m[x + 1] + 1;
            result = max(result, m[x]);
            continue;
        }

        if (m.find(x + 1) == m.end())
        {
            m[x] = m[x - m[x - 1]] = m[x - 1] + 1;
            result = max(result, m[x]);
            continue;
        }

        m[x] = m[x - m[x - 1]] = m[x + m[x + 1]] = m[x - 1] + m[x + 1] + 1;
        result = max(result, m[x]);
    }

    return result;
}

void testLongestConsecutive()
{
    vector<int> nums = { 100, 4, 200, 1, 3, 2 };
    cout << longestConsecutive2(nums) << endl;
}

int main()
{
    testLongestConsecutive();
    getchar();
}