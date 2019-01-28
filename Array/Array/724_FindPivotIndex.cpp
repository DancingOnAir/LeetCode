#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums)
{
    size_t n = nums.size();
    if (n < 3)
        return -1;

    for (int i = 0; i < n; ++i)
    {
        int s1 = 0, s2 = 0;
        int j = 0;
        while (j < i)
        {
            s1 += nums[j++];
        }

        j = i + 1;
        while (j < n)
        {
            s2 += nums[j++];
        }

        if (s1 == s2)
            return i;
    }

    return -1;
}

int pivotIndex2(vector<int>& nums)
{
    size_t n = nums.size();
    if (n < 3)
        return -1;
    
    int total = 0, sum = 0;
    for (auto x : nums)
        total += x;

    for (int i = 0; i < n; sum += nums[i++])
    {
        if (sum * 2 == total - nums[i])
            return i;
    }

    return -1;
}

void testPivotIndex()
{
    vector<int> nums = { 1, 7, 3, 6, 5, 6 };
    cout << pivotIndex2(nums) << endl;
}

int main()
{
    testPivotIndex();

    getchar();
    return 0;
}