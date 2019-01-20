#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findShortestSubArray(vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.size();

    int maxCount = 0;
    int minInterval = 0;
    int curCount = 0;
    int curInterval = 0;

    unordered_map<int, int> startPos;
    unordered_map<int, int> repeat;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (repeat.find(nums[i]) == repeat.end())
        {
            repeat[nums[i]] = 1;
            startPos[nums[i]] = i;

            curInterval = 0;
        }
        else
        {
            repeat[nums[i]]++;
            curInterval = i - startPos[nums[i]];
        }

        curCount = repeat[nums[i]];

        if (maxCount < curCount || (maxCount == curCount && minInterval > curInterval))
        {
            maxCount = curCount;
            minInterval = curInterval;
        }

    }

    return minInterval + 1;
}

int findShortestSubArray2(vector<int>& nums)
{
    unordered_map<int, vector<int>> m;
    int maxCount = 0;
    int minInterval = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        m[nums[i]].emplace_back(i);

        if (maxCount < m[nums[i]].size())
        {
            maxCount = m[nums[i]].size();
            minInterval = m[nums[i]][m[nums[i]].size() - 1] - m[nums[i]][0];

        }
        else if (maxCount == m[nums[i]].size())
        {
            minInterval = min(minInterval, m[nums[i]][m[nums[i]].size() - 1] - m[nums[i]][0]);
        }
    }

    return minInterval + 1;

}

void testFindShortestSubArray()
{
    vector<int> nums1 = { 1,2,2,3,1,4,2 };
    vector<int> nums2 = { 1, 2, 2, 3, 1 };

    cout << findShortestSubArray2(nums1) << endl;
}

int main()
{
    testFindShortestSubArray();

    getchar();
    return 0;
}