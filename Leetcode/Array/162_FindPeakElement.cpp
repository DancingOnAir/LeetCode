//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int findPeakElement(vector<int>& nums)
//{
//    for (int i = 1; i < nums.size(); ++i)
//    {
//        if (nums[i] < nums[i - 1])
//            return i - 1;
//    }
//
//
//    return nums.size() - 1;
//}
//
//int helper(const vector<int>& nums, int left, int right)
//{
//    if (left == right)
//        return left;
//    else
//    {
//        int mid1 = left + (right - left) / 2;
//        int mid2 = mid1 + 1;
//
//        if (nums[mid1] > nums[mid2])
//            return helper(nums, left, mid1);
//        else
//            return helper(nums, mid2, right);
//    }
//}
//
//int findPeakElement2(vector<int>& nums)
//{
//    if (nums.size() < 2)
//        return nums.size() - 1;
//
//    return helper(nums, 0, nums.size() - 1);
//}
//
//void testFindPeakElement()
//{
//    vector<int> nums = { 1,2,1,3,5,6,4 };
//    vector<int> nums2 = {};
//    cout << findPeakElement(nums) << endl;
//}
//
//int main()
//{
//    testFindPeakElement();
//    getchar();
//    return 0;
//}