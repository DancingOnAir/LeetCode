//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int findMin(vector<int>& nums)
//{
//    if (nums.empty())
//        return INT_MIN;
//
//    if (1 == nums.size())
//        return nums[0];
//
//    int left = 0, right = nums.size() - 1;
//    while (left < right && nums[left] <= nums[left + 1]) ++left;
//
//    if (left == right)
//        return nums[0];
//        
//    return nums[left + 1];
//}
//
//int findMin2(vector<int>& nums)
//{
//    if (nums.empty())
//        return INT_MIN;
//
//    int left = 0, right = nums.size() - 1;
//
//    while (left < right)
//    {
//        if (nums[left] < nums[right])
//            return nums[left];
//
//        int mid = left + (right - left) / 2;
//        if (nums[mid] >= nums[left])
//            left = mid + 1;
//        else
//            right = mid;
//    }
//
//    return nums[left];
//}
//
//void testFindMin()
//{
//    vector<int> nums = { 4,5,6,7,0,1,2 };
//    cout << findMin2(nums) << endl;
//}
//
//int main()
//{
//    testFindMin();
//    getchar();
//}