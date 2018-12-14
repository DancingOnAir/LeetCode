//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int trap(vector<int>& height)
//{
//    if (height.size() < 3)
//        return 0;
//
//    int left = 0, right = height.size() - 1, level = 0, lower = 0;
//    int res = 0;
//
//    while (left < right)
//    {
//        lower = height[height[left] < height[right] ? left++ : right--];
//        level = level > lower ? level : lower;
//        res += level - lower;
//    }
//
//    return res;
//}
//
//void testTrap()
//{
//    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//    vector<int> height2 = { 5, 2, 1, 2, 1, 5};
//    cout << trap(height2) << endl;
//}
//
//int main()
//{
//    testTrap();
//    getchar();
//}