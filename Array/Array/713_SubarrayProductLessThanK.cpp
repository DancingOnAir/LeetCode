//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int calculateProduct(vector<int>& nums)
//{
//    if (nums.empty())
//        return 0;
//
//    int res = 1;
//    for (int x : nums)
//        res *= x;
//
//    return res;
//}
//
//void dfs(vector<int>& nums, int k, int& res, vector<int>& path, int pos)
//{
//    if (calculateProduct(path) >= k)
//    {
//        return;
//    }
//
//    if (!path.empty())
//        ++res;
//
//    if (pos >= nums.size())
//        return;
//
//    path.emplace_back(nums[pos]);
//    dfs(nums, k, res, path, pos + 1);
//    path.pop_back();
//}
//
//int numSubarrayProductLessThanK(vector<int>& nums, int k)
//{
//    if (nums.empty())
//        return 0;
//
//    vector<int> path;
//    int res = 0;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        dfs(nums, k, res, path, i);
//    }
//
//    return res;
//}
//
//int numSubarrayProductLessThanK2(vector<int>& nums, int k)
//{
//    if (k == 0)
//        return 0;
//
//    int prod = 1;
//    int res = 0;
//    int left = 0;
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        prod *= nums[i];
//        while (prod >= k && left <= i)
//            prod /= nums[left++];
//
//        res += i - left + 1;
//    }
//
//    return res;
//}
//
//void testNumSubarrayProductLessThanK()
//{
//    vector<int> nums = { 10, 5, 2, 6 };
//    int k = 100;
//
//    cout << numSubarrayProductLessThanK2(nums, k) << endl;
//}
//
//int main()
//{
//    testNumSubarrayProductLessThanK();
//    getchar();
//    return 0;
//}