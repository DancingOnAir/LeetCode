#include <iostream>
#include <vector>

using namespace std;

int findUnsortedSubarray(vector<int>& nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;

    int left = 0, right = n - 1;
    while (left + 1 < n && nums[left + 1] >= nums[left])
        ++left;

    if (left == n - 1)
        return 0;

    while (nums[right - 1] <= nums[right])
        --right;

    int rmin = INT_MAX, lmax = INT_MIN;
    for (int i = left; i <= right; ++i)
    {
        if (nums[i] > lmax)
            lmax = nums[i];

        if (nums[i] < rmin)
            rmin = nums[i];
    }

    while (left >= 0 && nums[left] > rmin) --left;
    while (right < n && nums[right] < lmax) ++right;

    return right - left - 1;
}

void testFindUnsortedSubarray()
{
    vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
    vector<int> nums2 = { 1,2,3,3,3};
    cout << findUnsortedSubarray(nums2) << endl;
}

int main()
{
    testFindUnsortedSubarray();

    getchar();
    return 0;
}