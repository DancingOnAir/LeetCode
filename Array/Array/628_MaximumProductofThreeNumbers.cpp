//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maximumProduct(vector<int>& nums)
//{
//    size_t n = nums.size();
//
//    sort(nums.begin(), nums.end());
//
//    return max(nums[0] * nums[1] * nums[n - 1], nums[n - 3] * nums[n - 2] * nums[n - 1]);
//}
//
//int maximumProduct2(vector<int>& nums)
//{
//    vector<int> vecMax = { -1001, -1001, -1001 };
//    vector<int> vecMin = { 1001, 1001 };
//
//    for (auto x : nums)
//    {
//        if (x >= vecMax[0])
//        {
//            vecMax[2] = vecMax[1];
//            vecMax[1] = vecMax[0];
//            vecMax[0] = x;
//        }
//        else if (x > vecMax[1])
//        {
//            vecMax[2] = vecMax[1];
//            vecMax[1] = x;
//        }
//        else if (x > vecMax[2])
//        {
//            vecMax[2] = x;
//        }
//
//        if (x <= vecMin[0])
//        {
//            vecMin[1] = vecMin[0];
//            vecMin[0] = x;
//        }
//        else if (x < vecMin[1])
//        {
//            vecMin[1] = x;
//        }
//    }
//
//    return max(vecMax[1] * vecMax[2], vecMin[0] * vecMin[1]) * vecMax[0];
//}
//
//void testMaximumProduct()
//{
//    vector<int> nums = { 1,2,3,4 };
//    cout << maximumProduct2(nums) << endl;
//}
//
//int main()
//{
//    testMaximumProduct();
//
//    getchar();
//    return 0;
//}