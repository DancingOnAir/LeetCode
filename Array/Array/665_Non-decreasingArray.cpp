//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool checkPossibility(vector<int>& nums)
//{
//    if (nums.size() < 2)
//        return nums.size();
//
//    int count = 0;
//    for (int i = 0; i < nums.size() - 1; ++i)
//    {
//        if (nums[i] > nums[i + 1])
//        {
//            if (0 == i || nums[i - 1] <= nums[i + 1] || nums.size() - 2 == i || nums[i] <= nums[i + 2])
//                ++count;
//            else
//                return false;
//        }
//
//    }
//
//    return count < 2;
//}
//
//bool checkPossibility2(vector<int>& nums)
//{
//    for (int i = 1; i < nums.size(); ++i)
//    {
//        if (nums[i - 1] <= nums[i])
//            continue;
//
//        int temp = nums[i - 1];
//        nums[i - 1] = nums[i];
//
//        if (is_sorted(nums.begin(), nums.end()))
//            return true;
//
//        nums[i - 1] = nums[i] = temp;
//        return (is_sorted(nums.begin(), nums.end()));
//    }
//
//    return true;
//}
//
//void testCheckPossibility()
//{
//    vector<int> nums = { 2, 3, 3, 2, 4 };
//    cout << (checkPossibility(nums) ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testCheckPossibility();
//    getchar();
//    return 0;
//}