//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int wiggleMaxLength(vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//
//    int n = nums.size();
//    if (1 == n)
//        return 1;
//
//    vector<int> greater(n, 1);
//    vector<int> less(n, 1);
//
//    for (int i = 1; i < n; ++i)
//    {
//        if (nums[i] > nums[i - 1])
//        {
//            greater[i] = less[i - 1] + 1;
//            less[i] = less[i - 1];
//        }
//        else if (nums[i] < nums[i - 1])
//        {
//            greater[i] = greater[i - 1];
//            less[i] = greater[i - 1] + 1;
//        }
//        else
//        {
//            greater[i] = greater[i - 1];
//            less[i] = less[i - 1];
//        }
//    }
//    return max(greater[n - 1], less[n - 1]);
//}
//
//void testWiggleMaxLength()
//{
//    vector<int> nums1{ 1,17,5,10,13,15,10,5,16,8 };
//    vector<int> nums2{ 3, 3, 3, 2, 5 };
//    cout << wiggleMaxLength(nums1) << endl;
//}
//
//int main()
//{
//    testWiggleMaxLength();
//
//    getchar();
//    return 0;
//}