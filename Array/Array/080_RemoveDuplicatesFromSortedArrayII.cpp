#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) 
{
    //if (nums.size() < 3)
    //    return nums.size();

    //int index = 2;
    //int count = 0;

    //if (nums[0] == nums[1])
    //    count = 2;
    //else
    //    count = 1;

    //for (int i = 2; i < nums.size(); ++i)
    //{
    //    if (nums[i] != nums[i - 1] || count == 1)
    //    {
    //        if (nums[i] == nums[i - 1])
    //            count = 2;
    //        else
    //            count = 1;

    //        nums[index++] = nums[i];
    //    }
    //}

    //return index;

    int i = 0;
    for (int n : nums)
    {
        if (i < 2 || nums[i - 2] < n)
            nums[i++] = n;
    }

    return i;
}

int main()
{
    std::vector<int> input = { 0,0,1,1,1,1,2,3,3 };
    int result = removeDuplicates(input);
    std::cout << result << std::endl;

    system("pause");
    return 0;
}