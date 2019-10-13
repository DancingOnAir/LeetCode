//#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <set>
//#include <algorithm>
//#include <iterator>
//using namespace std;
//
//vector<int> intersection2(vector<int>& nums1, vector<int>& nums2)
//{
//    if (nums1.empty() || nums2.empty())
//        return vector<int>();
//
//    unordered_set<int> m(nums1.begin(), nums1.end());
//    
//    vector<int> res;
//    for (int x : nums2)
//    {
//        if (m.count(x))
//        {
//            res.emplace_back(x);
//            m.erase(x);
//        }
//    }
//
//    return res;
//}
//
//vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//{
//    sort(nums1.begin(), nums1.end());
//    sort(nums2.begin(), nums2.end());
//
//    set<int> res;
//    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::inserter(res, res.end()));
//    return vector<int>(res.begin(), res.end());
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
//    auto res1 = intersection(nums11, nums21);
//    display(std::move(res1));
//
//    vector<int> nums12 = { 4, 9, 5 };
//    vector<int> nums22 = { 9, 4, 9, 8, 4 };
//    auto res2 = intersection(nums12, nums22);
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