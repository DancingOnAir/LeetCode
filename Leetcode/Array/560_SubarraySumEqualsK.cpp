//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//int subarraySum(vector<int>& nums, int k)
//{
//    if (nums.empty())
//        return 0;
//
//    int res = 0;
//    int sum = 0;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        sum = 0;
//        for (int j = i; j < nums.size(); ++j)
//        {
//            sum += nums[j];
//
//            if (sum == k)
//            {
//                ++res;
//            }
//            else
//                continue;
//        }
//    }
//
//    return res;
//}
//
//int subarraySum2(vector<int>& nums, int k)
//{
//    int res = 0;
//    int sum = 0;
//    unordered_map<int, int> m;
//    m[0]++;
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        sum += nums[i];
//
//        if (m.find(sum - k) != m.end())
//            res += m[sum - k];
//
//        m[sum]++;
//    }
//
//    return res;
//}
//
//void testSubarraySum()
//{
//    vector<int> nums = { 1, 1, 1 };
//    int k = 2;
//
//    cout << subarraySum2(nums, k) << endl;
//}
//
//int main()
//{
//    testSubarraySum();
//
//    getchar();
//    return 0;
//}