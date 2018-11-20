//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool search(vector<int>& nums, int target) 
//{
//    if (nums.empty())
//        return false;
//
//    int start = 0;
//    int end = nums.size() - 1;
//    
//    while (start < end)
//    {
//        int mid = start + (end - start) / 2;
//
//        if (nums[mid] == target)
//            return true;
//
//        if (nums[mid] > nums[end])
//        {
//            if (nums[mid] > target&& target >= nums[start])
//                end = mid;
//            else
//                start = mid + 1;
//        }
//        else if (nums[mid] < nums[end])
//        {
//            if (target > nums[mid] && target <= nums[end])
//                start = mid + 1;
//            else
//                end = mid;
//        }
//        else
//            --end;
//    }
//
//    return nums[start] == target;
//}
//
//void testSearch()
//{
//    vector<int> nums = { 2, 5, 6, 0, 0, 1, 2 };
//    int target = 3;
//
//    bool result = search(nums, target);
//    cout << (result ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testSearch();
//    getchar();
//}