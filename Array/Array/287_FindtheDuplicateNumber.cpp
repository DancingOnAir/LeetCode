//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int findDuplicate(vector<int>& nums)
//{
//    sort(nums.begin(), nums.end());
//    for (unsigned int i = 0; i < nums.size() - 1; ++i)
//    {
//        if (nums[i] == nums[i + 1])
//            return nums[i];
//    }
//
//    return -1;
//}
//
//int findDuplicate2(vector<int>& nums)
//{
//    if (nums.size() > 1)
//    {
//        int slow = nums[0];
//        int fast = nums[slow];
//
//        while (slow != fast)
//        {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//        }
//
//        fast = 0;
//        while (slow != fast)
//        {
//            slow = nums[slow];
//            fast = nums[fast];
//        }
//
//        return slow;
//    }
//
//    return -1;
//}
//
//int findDuplicate3(vector<int>& nums)
//{
//    int n = nums.size() - 1;
//    int low = 1;
//    int high = n;
//    int count = 0, mid = 0;
//    while (low < high)
//    {
//        mid = low + (high - low) / 2;
//        count = 0;
//
//        for (auto& x : nums)
//            if (x <= mid)
//                ++count;
//
//        if (count > mid)
//            high = mid;
//        else
//            low = mid + 1;
//    }
//
//    return low;
//}
//
//void testFindDuplicate()
//{
//    vector<int> nums = { 1,3,4,2,2 };
//    cout << findDuplicate3(nums) << endl;
//}
//
//int main()
//{
//    testFindDuplicate();
//    getchar();
//    return 0;
//}