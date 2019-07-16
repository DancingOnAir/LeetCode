//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//using namespace std;
//
//int minMoves(vector<int>& nums)
//{
//    size_t len = nums.size();
//    if (len < 2)
//        return 0;
//
//    sort(nums.begin(), nums.end());
//
//    int res = 0;
//    for (int i = len - 1; i > 0; --i)
//    {
//        res += nums[i] - nums[0];
//    }
//
//    return res;
//}
//
//int minMoves2(vector<int>& nums)
//{
//    return accumulate(nums.begin(), nums.end(), 0L) - nums.size() * (*min_element(nums.begin(), nums.end()));
//}
//
//void testMinMoves()
//{
//    vector<int> nums = { 1, 2, 3 };
//    cout << minMoves2(nums) << endl;
//}
//
//int main()
//{
//    testMinMoves();
//
//    getchar();
//    return 0;
//}