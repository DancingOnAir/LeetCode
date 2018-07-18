//#include <iostream>
//#include <set>
//#include <vector>
//#include <stdlib.h>
//
//using namespace std;
//int firstMissingPositive(vector<int>& nums) 
//{
//    if (nums.size() == 0)
//        return 1;
//
//    set<int> s(nums.cbegin(), nums.cend());
//    int result = 0;
//
//    result = 0;
//
//    for (auto iter = s.begin(); iter != s.end(); ++iter)
//    {
//
//        if (*iter < 1)
//        {
//            continue;
//        }
//
//        if (*iter != ++result)
//            return result;
//    }
//
//    return result + 1;
//}
//
//void display(const vector<int>& vec)
//{
//    for (const auto &v : vec)
//    {
//        cout << v << endl;
//    }
//}
//
//int main()
//{
//    vector<int> input1 = { 0 };
//    vector<int> input2 = { 3, 4, -1, 1 };
//    vector<int> input3 = { 7, 8, 9, 11, 12 };
//    display(input3);
//    cout << firstMissingPositive(input3) << endl;
//
//    system("pause");
//    return 0;
//}
