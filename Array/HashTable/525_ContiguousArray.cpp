#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findMaxLength(vector<int>& nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;

    unordered_map<int, int> m;
    m[0] = -1;
    int res = 0, sum = 0;
    
    for (int i = 0; i < n; ++i)
    {
        sum += (nums[i] == 0) ? -1 : 1;
        auto iter = m.find(sum);
        if (iter != m.end())
            res = max(res, i - iter->second);
        else
            m[sum] = i;
    }

    return res;
}

void testFindMaxLength()
{
    vector<int> nums1 = { 0, 1 };
    cout << findMaxLength(nums1) << endl;

    vector<int> nums2 = { 0, 1, 0 };
    cout << findMaxLength(nums2) << endl;
}

int main()
{
    testFindMaxLength();

    getchar();
    return 0;
}