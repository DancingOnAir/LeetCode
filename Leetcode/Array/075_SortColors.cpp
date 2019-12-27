//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
//
//void sortColors(vector<int>& nums)
//{
//    if (nums.size() < 2)
//        return;
//    int low = 0, mid = 0, high = nums.size() - 1;
//    while(mid <= high)
//    {
//        if (nums[mid] == 0)
//        {
//            swap(nums[mid], nums[low]);
//            ++low;
//            ++mid;
//        }
//        else if (nums[mid] == 2)
//        {
//            swap(nums[mid], nums[high]);
//            --high;
//        }
//        else
//        {
//            ++mid;
//        }
//    }
//}
//
//void sortColors2(vector<int>& nums)
//{
//    int zero = 0;
//    int second = nums.size() - 1;
//    for (int i = 0; i <= second; ++i)
//    {
//        if (nums[i] == 0 && i != zero)
//            swap(nums[i--], nums[zero++]);
//        else if (nums[i] == 2 && i != second)
//            swap(nums[i--], nums[second--]);
//    }
//}
//
//void testSortColors()
//{
//    vector<int> nums = { 2,0,2,1,1,0 };
//    sortColors2(nums);
//
//    for (int x : nums)
//        cout << x << ",";
//    cout << endl;
//}
//
//int main()
//{
//    testSortColors();
//    getchar();
//}