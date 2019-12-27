//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//
//vector<int> findDuplicates(vector<int>& nums)
//{
//    vector<int> res;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (nums[abs(nums[i]) - 1] < 0)
//            res.emplace_back(abs(nums[i]));
//
//        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
//    }
//    return res;
//
//    //set<int> res;
//    //for (int i = 0; i < nums.size(); ++i)
//    //{
//    //    if (nums[i] > 0)
//    //        res.insert(nums[i]);
//    //}
//
//    //return vector<int>(res.begin(), res.end());
//}
//
//vector<int> findDuplicates2(vector<int>& nums)
//{
//    vector<int> res;
//    int i = 0;
//    while (i < nums.size())
//    {
//        if (nums[i] != nums[nums[i] - 1])
//            swap(nums[i], nums[nums[i] - 1]);
//        else
//            ++i;
//    }
//
//    for (i = 0; i < nums.size(); ++i)
//    {
//        if (i + 1 != nums[i])
//            res.emplace_back(nums[i]);
//    }
//
//    return res;
//}
//
//void testFindDuplicates()
//{
//    vector<int> nums = { 4,3,2,7,8,2,3,1 };
//    vector<int> nums2 = { 10,2,5,10,9,1,1,4,3,7 };
//    auto res = findDuplicates2(nums2);
//
//    for (auto x : res)
//        cout << x << ", ";
//
//    cout << endl;
//}
//
//int main()
//{
//    testFindDuplicates();
//    getchar();
//    return 0;
//}