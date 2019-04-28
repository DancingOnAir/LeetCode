//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include <bitset>
//using namespace std;
//
//bool canPartition(vector<int>& nums)
//{
//    int n = nums.size();
//    if (n < 2)
//        return false;
//
//    int sum = accumulate(nums.begin(), nums.end(), 0);
//    int mid = sum >> 1;
//    if (sum & 1)
//        return false;
//
//    vector<bool> dp(mid + 1);
//    dp[0] = true;
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        for (int j = mid; j > 0; --j)
//        {
//            if (j >= nums[i])
//                dp[j] = dp[j] || dp[j - nums[i]];
//        }
//    }
//
//    return dp[mid];
//}
//
//bool canPartition2(vector<int>& nums)
//{
//    int sum = accumulate(nums.begin(), nums.end(), 0);
//    bitset<10001> bits(1);
//    for (auto x : nums)
//        bits |= bits << x;
//
//    return !(sum & 1) && bits[sum >> 1];
//}
//
//void testCanPartition()
//{
//    vector<int> nums1 = { 1, 5, 11, 5 };
//    vector<int> nums2 = { 1, 2, 3, 5 };
//    cout << (canPartition(nums1) ? "True" : "False") << endl;
//    cout << (canPartition(nums2) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testCanPartition();
//
//    getchar();
//    return 0;
//}