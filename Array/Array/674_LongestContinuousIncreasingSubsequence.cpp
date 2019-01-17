#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.size();

    int res = 0;
    int count = 1;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] < nums[i + 1])
        {
            ++count;
        }
        else
            count = 1;

        if (res < count)
            res = count;
    }

    return res;
}

int findLengthOfLCIS2(vector<int>& nums)
{
    int res = 0, count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i == 0 || nums[i - 1] >= nums[i])
            count = 0;

        res = res > count ? res : ++count;
    }

    return res;
}

void testFindLengthOfLCIS()
{
    vector<int> nums = { 1,3,5,4,7 };
    vector<int> nums2 = { 2, 2, 2, 2, 2 };
    cout << findLengthOfLCIS2(nums2) << endl;
}

int main()
{
    testFindLengthOfLCIS();
    getchar();
    return 0;
}