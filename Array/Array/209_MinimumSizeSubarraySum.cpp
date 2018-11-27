#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
    if (s <= 0 || nums.empty())
        return 0;

    int minLen = 0;
    int sum = 0;
    for (unsigned int i = 0; i < nums.size(); ++i)
    {
        sum = 0;
        for (unsigned int j = i; j < nums.size(); ++j)
        {
            sum += nums[j];
            if (sum >= s )
            {
                if (0 == minLen || j - i + 1 < minLen)
                    minLen = j - i + 1;
            }
        }
    }

    return minLen;
}

int minSubArrayLen2(int s, vector<int>& nums)
{
    if (s <= 0 || nums.empty())
        return 0;

    unsigned int sum = 0, minLen = INT_MAX, start = 0;
    for (unsigned int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        while (sum >= s)
        {
            minLen = min(minLen, i - start + 1);
            sum -= nums[start++];
        }
    }

    return INT_MAX == minLen? 0: minLen;
}

void testMinSubArrayLen()
{
    vector<int> nums = { 2,3,1,2,4,3 };
    vector<int> nums2 = { 1, 1 };
    int s = 7;

    cout << minSubArrayLen2(s, nums) << endl;
}

int main()
{
    testMinSubArrayLen();
    getchar();
}