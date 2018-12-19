//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int majorityElement(vector<int>& nums)
//{
//    if (nums.size() == 1)
//        return nums[0];
//
//
//    map<int, int> m;
//    for (auto i = 0; i < nums.size(); ++i)
//    {
//        if (m.count(nums[i]))
//            ++m[nums[i]];
//        else
//            m[nums[i]] = 1;
//    }
//
//    int maxTimes = m[nums[0]];
//    int res = nums[0];
//    for (auto iter = m.begin(); iter != m.end(); ++iter)
//    {
//        if (maxTimes < iter->second)
//        {
//            maxTimes = iter->second;
//            res = iter->first;
//        }
//    }
//
//    return res;
//}
//
//int majorityElement2(vector<int>& nums)
//{
//    int candidate = 0;
//    int count = 0;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (count == 0)
//        {
//            candidate = nums[i];
//            count = 1;
//        }
//        else if (candidate == nums[i])
//        {
//            ++count;
//        }
//        else
//        {
//            --count;
//        }
//    }
//
//    return candidate;
//}
//
//void testMajorityElement()
//{
//    vector<int> nums = { 2,2,1,1,1,2,2 };
//    cout << majorityElement(nums) << endl;
//    cout << majorityElement2(nums) << endl;
//
//}
//
//int main()
//{
//    testMajorityElement();
//    getchar();
//}