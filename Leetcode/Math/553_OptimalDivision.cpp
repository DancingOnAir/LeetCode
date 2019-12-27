//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string optimalDivision2(vector<int>& nums)
//{
//    int n = nums.size();
//    if (0 == n)
//        return "";
//
//    if (1 == n)
//        return to_string(nums[0]);
//
//    string numerator(to_string(nums[0]));
//    string denominator("");
//    int count = 0;
//    for (int i = 1; i < n; ++i)
//    {
//        if (nums[i] < 1 && i != n - 1)
//        {
//            if (numerator.back() != ')')
//            {
//                numerator = '(' + numerator + ')';
//            }
//
//            if (count > 1)
//            {
//                denominator = '(' + denominator + ')';
//            }
//
//            numerator = '(' + numerator + '/' + denominator + ")/" + to_string(nums[i]) ;
//            denominator = "";
//            count = 0;
//        }
//        else
//        {
//            if (!denominator.empty())
//                denominator += '/';
//
//            denominator += to_string(nums[i]);
//            ++count;
//        }
//    }
//
//    if (count > 1)
//    {
//        denominator = '(' + denominator + ')';
//    }
//
//    return numerator + '/' + denominator;
//}
//
//string optimalDivision(vector<int>& nums)
//{
//    int n = nums.size();
//    string res;
//    for (int i = 0; i < n; ++i)
//    {
//        if (i > 0)
//            res += '/';
//
//        if (i == 1 && n > 2)
//            res += '(';
//
//        res += to_string(nums[i]);
//
//        if (i == n - 1 && n > 2)
//            res += ')';
//    }
//
//    return res;
//}
//
//void testOptimalDivision()
//{
//    vector<int> nums1{ 1000,100,10,2 };
//    cout << optimalDivision(nums1) << endl;
//
//    vector<int> nums2{ 3,2 };
//    cout << optimalDivision(nums2) << endl;
//}
//
//int main()
//{
//    testOptimalDivision();
//
//    getchar();
//    return 0;
//}