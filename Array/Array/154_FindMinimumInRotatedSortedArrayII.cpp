#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums)
{
    if (nums.empty())
        return INT_MIN;

    if (1 == nums.size())
        return nums[0];

    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] < nums[right])
            return nums[left];

        int mid = left + (right - left) / 2;
        if (nums[left] < nums[mid])
            left = mid + 1;
        else if (nums[left] > nums[mid])
            right = mid;
        else
            ++left;
    }

    return nums[left];
}

void testFindMin()
{
    vector<int> nums = { 2, 2, 2, 0, 1 };
    cout << findMin(nums) << endl;
}

int main()
{
    testFindMin();
    getchar();
}