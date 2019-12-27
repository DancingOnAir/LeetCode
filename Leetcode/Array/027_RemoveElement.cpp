//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//
//using namespace std;
//
//int removeElement(vector<int>& nums, int val) 
//{
//	for (vector<int>::iterator iter = nums.begin(); iter != nums.end();)
//	{
//		if (*iter == val)
//			iter = nums.erase(iter);
//		else
//			++iter;
//	}
//
//	for (auto val : nums)
//	{
//		cout << val << endl;
//	}
//
//	return nums.size();
//}
//
//int removeElement2(vector<int>& nums, int val) {
//	int cnt = 0;
//	for (int i = 0; i < nums.size(); ++i) {
//		if (nums[i] == val)
//			cnt++;
//		else
//			nums[i - cnt] = nums[i];
//	}
//
//	for (auto val : nums)
//	{
//		cout << val << endl;
//	}
//	cout << "end of vector" << endl;
//	return nums.size() - cnt;
//}
//
//int removeElement3(vector<int> &nums, int val)
//{
//
//    for (auto iter = nums.begin(); iter != nums.end();)
//    {
//        if (val == *iter)
//            iter = nums.erase(iter);
//        else
//            ++iter;
//    }
//
//    return nums.size();
//}
//
//int main(void)
//{
//    int a[] = { 3, 2, 2, 3, 4, 3 };
//    int size = sizeof(a) / sizeof(int);
//    int target = 3;
//    vector<int> vec(a, a + size);
//
//    //cout << removeElement(vec, target) << endl;
//    //cout << removeElement2(vec, target) << endl;
//    cout << removeElement3(vec, target) << endl;
//    system("pause");
//    return 0;
//}