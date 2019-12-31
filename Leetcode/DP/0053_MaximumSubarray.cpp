#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int res = 0;
    int sum = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i - 1] > 0)
            nums[i] += nums[i - 1];

        res = res > nums[i] ? res : nums[i];
    }

    return res;
}

void testMaxSubArray()
{
    vector<int> nums1 = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSubArray(nums1) << endl;
}

int main()
{
    testMaxSubArray();

    getchar();
    return 0;
}