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
    int res = 0, tmp = 0;
    for (int i = 0; i + res < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            ++m[nums[j]];
            if (m[0] == m[1])
            {
                res = max(res, m[0] * 2);
            }
        }

        m.clear();
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