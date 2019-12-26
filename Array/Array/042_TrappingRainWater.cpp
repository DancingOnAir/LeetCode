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

#include <iostream>
#include <vector>

using namespace std;

int trap2(vector<int>& height)
{
    int n = height.size();
    if (n < 3)
        return 0;

    int left = 0;
    int right = n - 1;
    int lower = 0;
    int level = 0;
    int res = 0;

    while (left < right)
    {
        lower = height[height[left] < height[right] ? left++ : right--];
        level = level > lower ? level : lower;
        res += level - lower;
    }

    return res;
}

int trap(vector<int>& height)
{
    int n = height.size();
    if (n < 3)
        return 0;

    int sumMap = 0, sumTot = 0;
    for (int x : height)
        sumMap += x;

    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;

    while (left <= right)
    {
        maxLeft = maxLeft > height[left] ? maxLeft : height[left];
        maxRight = maxRight > height[right] ? maxRight : height[right];

        if (maxLeft <= maxRight)
        {
            sumTot += maxLeft;
            ++left;
        }
        else
        {
            sumTot += maxRight;
            --right;
        }

    }

    return sumTot - sumMap;
}

void testTrap()
{
    vector<int> height1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << trap(height1) << endl;
}

int main()
{
    testTrap();

    getchar();
    return 0;
}