//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//vector<string> summaryRanges(vector<int>& nums)
//{
//    vector<string> result;
//    if (nums.empty())
//        return result;
//
//    int gap = nums[0];
//    size_t start = 0;
//    string slot;
//    for (size_t i = 1; i < nums.size(); ++i)
//    {
//        if (nums[i] - nums[i - 1] != 1)
//        {
//            slot = (start == i-1? to_string(nums[start]):to_string(nums[start]) + "->" + to_string(nums[i - 1]));
//            start = i;
//            result.emplace_back(slot);
//        }
//        else
//        {
//            if (i != nums.size() - 1)
//                continue;
//        }
//    }
//
//    slot = (start == nums.size() - 1 ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums[nums.size() - 1]));
//    result.emplace_back(slot);
//    return result;
//}
//
//vector<string> summaryRanges2(vector<int>& nums)
//{
//    const int len = nums.size();
//    vector<string> result;
//    if (0 == len)
//        return result;
//
//    for (int i = 0; i < len;)
//    {
//        int start = i, end = i;
//        while (end + 1 < len && nums[end + 1] - nums[end] == 1)
//            ++end;
//
//        if (end > start)
//            result.emplace_back(to_string(nums[start]) + "->" + to_string(nums[end]));
//        else
//            result.emplace_back(to_string(nums[start]));
//
//        i = end + 1;
//    }
//
//    return result;
//}
//
//void testSummaryRanges()
//{
//    vector<int> nums = { 0,2,3,4,6,8,9 };
//    vector<int> nums2 = { 0,1,2,4,5,7 };
//    vector<string> result = summaryRanges(nums);
//
//    for (auto& s : result)
//        cout << s << endl;
//}
//
//int main()
//{
//    testSummaryRanges();
//    getchar();
//}