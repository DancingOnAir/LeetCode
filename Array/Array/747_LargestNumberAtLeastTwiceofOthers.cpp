#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dominantIndex(vector<int>& nums)
{
    //if (nums.empty())
    //    return -1;

    //if (nums.size() == 1)
    //    return 0;

    int maxNum = 0;
    int secMaxNum = 0;
    int pos = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > secMaxNum)
        {
            if (nums[i] > maxNum)
            {
                secMaxNum = maxNum;
                maxNum = nums[i];
                pos = i;
            }
            else
            {
                secMaxNum = nums[i];
            }
        }
    }

    if (maxNum >= 2 * secMaxNum)
        return pos;

    return -1;
}

void testDominantIndex()
{
    vector<int> nums1 = { 3, 6, 1, 0 };
    vector<int> nums2 = { 1, 2, 3, 4 };
    vector<int> nums3 = { 0, 0, 0, 1 };
    vector<int> nums4 = { 0, 0, 3, 2 };

    cout << dominantIndex(nums1) << endl;
    cout << dominantIndex(nums2) << endl;
    cout << dominantIndex(nums3) << endl;
    cout << dominantIndex(nums4) << endl;
}

int main()
{
    testDominantIndex();

    getchar();
    return 0;
}