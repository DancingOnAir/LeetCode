//#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
//vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
//{
//    if (nums1.empty() || nums2.empty())
//        return vector<int>();
//
//    sort(nums1.begin(), nums1.end());
//    sort(nums2.begin(), nums2.end());
//
//    vector<int> res;
//    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));
//    return res;
//}
//
//void display(vector<int>&& nums)
//{
//    if (nums.empty())
//        return;
//
//    for (int x : nums)
//        cout << x << ", ";
//    cout << endl;
//}
//
//void testIntersection()
//{
//    vector<int> nums11 = { 1, 2, 2, 1 };
//    vector<int> nums21 = { 2, 2 };
//    auto res1 = intersect(nums11, nums21);
//    display(std::move(res1));
//
//    vector<int> nums12 = { 4, 9, 5 };
//    vector<int> nums22 = { 9, 4, 9, 8, 4 };
//    auto res2 = intersect(nums12, nums22);
//    display(std::move(res2));
//}
//
//int main()
//{
//    testIntersection();
//
//    getchar();
//    return 0;
//}