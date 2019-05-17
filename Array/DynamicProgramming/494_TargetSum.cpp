#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findTargetSumWays(vector<int>& nums, int S)
{
    if (nums.empty())
        return 0;

    int sum = 0;
    for (int x : nums)
        sum += x;

    if (S < -sum || S > sum)
        return 0;

    int tempS = S;
    int n = nums.size();
    unordered_map<int, vector<int>> m;
    vector<int> vec;

    for (int i = 0; i < n; ++i)
    {

        if (m.find(i - 1) != m.end())
        {
            auto previousVec = m[i - 1];

            for (int x : previousVec)
            {
                vec.emplace_back(x + nums[i]);
                vec.emplace_back(x - nums[i]);
            }
        }
        else
        {
            vec.emplace_back(nums[i]);
            vec.emplace_back(-nums[i]);
        }

        m[i] = vec;
        vec.clear();
    }

    int res = 0;
    for (int x : m[n - 1])
    {
        if (x == S)
            ++res;
    }

    return res;
}

void testFindTargetSumWays()
{
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int S = 3;

    cout << findTargetSumWays(nums, S) << endl;
}

int main()
{
    testFindTargetSumWays();

    getchar();
    return 0;
}