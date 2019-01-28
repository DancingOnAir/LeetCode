//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int smallestDistancePair(vector<int>& nums, int k)
//{
//    if (nums.size() < 2)
//        return 0;
//
//    int res = 0;
//    map<int, int> m;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        for (int j = i + 1; j < nums.size(); ++j)
//        {
//            ++m[abs(nums[j] - nums[i])];
//        }
//    }
//
//    for (auto iter = m.begin(); iter != m.end(); ++iter)
//    {
//        k -= iter->second;
//
//        if (k <= 0)
//        {
//            res = iter->first;
//            break;
//        }
//    }
//
//    return res;
//}
//
//int smallestDistancePair2(vector<int>& nums, int k)
//{
//    if (nums.size() < 2)
//        return 0;
//
//    int n = nums.size();
//    sort(nums.begin(), nums.end());
//
//    int l = 0;
//    int r = nums[n - 1] - nums[0];
//
//    for (int cnt = 0; l < r; cnt = 0)
//    {
//        int mid = l + (r - l) / 2;
//        for (int i = 0, j = 0; i < n; ++i)
//        {
//            while (j < n && nums[j] <= nums[i] + mid)
//                ++j;
//
//            cnt += j - i - 1;
//        }
//
//        if (cnt < k)
//            l = mid + 1;
//        else
//            r = mid;
//    }
//
//    return l;
//}
//
//void testSmallestDistancePair()
//{
//    vector<int> nums = { 1, 3, 1 };
//    int k = 1;
//
//    cout << smallestDistancePair2(nums, k) << endl;
//}
//
//int main()
//{
//    testSmallestDistancePair();
//
//    getchar();
//    return 0;
//}