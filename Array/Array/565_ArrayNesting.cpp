#include <iostream>
#include <vector>

using namespace std;

int arrayNesting(vector<int>& nums)
{
    if (nums.size() <= 1)
        return nums.size();

    int res = 0, count = 0;
    int temp = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        count = 0;
        
        for (int k = i; nums[k] >= 0; ++count)
        {
            temp = nums[k];
            nums[k] = -1;
            k = temp;
        }

        if (res < count)
            res = count;

        if (res > nums.size() / 2)
            break;
    }

    return res;
}

void testArrayNesting()
{
    vector<int> nums = { 5,4,0,3,1,6,2 };
    cout << arrayNesting(nums) << endl;
}

int main()
{
    testArrayNesting();

    getchar();
    return 0;
}