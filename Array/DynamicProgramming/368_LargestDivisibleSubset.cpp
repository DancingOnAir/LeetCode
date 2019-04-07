#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset2(vector<int>& nums)
{
    vector<int> res;
    if (nums.empty())
        return res;

    int n = nums.size();
    if (n == 1)
    {
        res.emplace_back(nums[0]);
        return res;
    }

    sort(nums.begin(), nums.end());
    vector<vector<int>> sub(n);
    sub[0].emplace_back(nums[0]);
    int max = 1;
    int max_index = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] % nums[j] == 0 && sub[i].size() < sub[j].size())
            {
                sub[i] = sub[j];
            }
        }

        sub[i].emplace_back(nums[i]);
        if (sub[i].size() > max)
        {
            max = sub[i].size();
            max_index = i;
        }
    }

    return sub[max_index];
}

vector<int> largestDivisibleSubset(vector<int>& nums)
{
    vector<int> res;
    if (nums.empty())
        return res;

    int n = nums.size();
    if (1 == n)
    {
        res.emplace_back(nums[0]);
        return res;
    }

    int maxSize = 0;
    int maxIndex = 0;

    vector<int> dp(n, 1);
    vector<int> parents(n);

    sort(nums.begin(), nums.end());

    for (int j = 1; j < n; ++j)
    {
        for (int i = j - 1; i >= 0; --i)
        {
            if (nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1)
            {
                dp[j] = dp[i] + 1;
                parents[j] = i;
            }
        }

        if (dp[j] > maxSize)
        {
            maxSize = dp[j];
            maxIndex = j;
        }
    }

    for (int i = 0; i < maxSize; ++i)
    {
        res.emplace_back(nums[maxIndex]);
        maxIndex = parents[maxIndex];
    }

    return res;
}

void testLargestDivisibleSubset()
{
    vector<int> nums{ 546, 669 };
    auto res = largestDivisibleSubset(nums);

    for (int x : res)
        cout << x << ", ";
    cout << endl;
}

int main()
{
    testLargestDivisibleSubset();

    getchar();
    return 0;
}