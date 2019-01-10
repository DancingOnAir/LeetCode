//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int triangleNumber(vector<int>& nums)
//{
//    int n = nums.size();
//    int res = 0;
//    if (n < 3)
//        return res;
//
//    sort(nums.begin(), nums.end());
//
//    for (int tail = n - 1; tail > 1; --tail)
//    {
//        int j = 0, k = tail - 1;
//        while (j < k)
//        {
//            if (nums[j] + nums[k] > nums[tail])
//            {
//                res += (k - j);
//                --k;
//            }
//            else
//                ++j;
//        }
//    }
//
//    return res;
//}
//
//void testTriangleNumber()
//{
//    vector<int> nums = { 2,2,3,4 };
//    cout << triangleNumber(nums) << endl;
//}
//
//int main()
//{
//    testTriangleNumber();
//
//    getchar();
//    return 0;
//}