//#include <iostream>
//#include <vector>
//#include <set>
//#include <unordered_map>
//using namespace std;
//
//bool containsNearbyDuplicate(vector<int>& nums, int k)
//{
//    if (nums.empty() || k <= 0)
//        return false;
//
//    set<int> candidates;
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (i > k)
//            candidates.erase(nums[i - k - 1]);
//        if (!candidates.insert(nums[i]).second)
//            return true;
//    }
//
//    return false;
//}
//
//bool containsNearbyDuplicate2(vector<int>& nums, int k)
//{
//    if (nums.empty() || k <= 0)
//        return false;
//
//    unordered_map<int, int> m;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)
//            return true;
//
//        m[nums[i]] = i;
//    }
//
//    return false;
//}
//
//void testContainNearbyDuplicate()
//{
//    vector<int> nums = { 1,2,3,1 };
//    vector<int> nums2 = { 1,2,3,1,2,3 };
//    int k = 3;
//
//    cout << (containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;
//    cout << (containsNearbyDuplicate(nums2, 2) ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testContainNearbyDuplicate();
//    getchar();
//}