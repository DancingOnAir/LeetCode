//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void dfs(vector<int>& nums, int index, int& product, int& maxProduct)
//{
//    product *= nums[index];
//    if (product > maxProduct)
//        maxProduct = product;
//
//    if (index == nums.size())
//    {
//        return;
//    }
//
//    dfs(nums, ++index, product, maxProduct);
//}
//
//int maxProduct(vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//
//    int maxResult = INT_MIN, tempResult = INT_MIN;
//    int start = INT_MIN;
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        for (int j = i; j < nums.size(); ++j)
//        {
//            if (INT_MIN == start)
//            {
//                start = j;
//                tempResult = nums[j];
//
//            }
//            else
//                tempResult *= nums[j];
//
//            if (tempResult > maxResult)
//                maxResult = tempResult;
//        }
//
//        start = INT_MIN;
//        tempResult = INT_MIN;
//    }
//
//    return maxResult;
//}
//
//int maxProduct2(vector<int>& nums)
//{
//    if (nums.empty())
//        return INT_MIN;
//
//    int temp = nums[0], minResult = 0, maxResult = 0;
//
//    for (int i = 1, minResult = temp, maxResult = temp; i < nums.size(); ++i)
//    {
//        if (nums[i] < 0)
//            swap(minResult, maxResult);
//
//        maxResult = std::max(maxResult * nums[i], nums[i]);
//        minResult = std::min(minResult * nums[i], nums[i]);
//
//        temp = max(maxResult, temp);
//    }
//
//    return temp;
//}
//
//void testMaxProduct()
//{
//    vector<int> nums1 = { 2, 3, -2, 4 };
//    vector<int> nums2 = { -1, -1 };
//    cout << maxProduct2(nums1) << endl;
//}
//
//int main()
//{
//    testMaxProduct();
//    getchar();
//}