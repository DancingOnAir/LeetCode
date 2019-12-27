//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//vector<int> searchRange(vector<int>& nums, int target) 
//{
//	//auto bounds = equal_range(nums.begin(), nums.end(), target);
//
//	//if (bounds.first == bounds.second)
//	//	return {-1, -1};
//	//return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
//
//	int size = nums.size();
//	int i = 0;
//	int j = size - 1;
//	int mid = 0;
//	vector<int> result(2, -1);
//
//	while (i < j)
//	{
//		mid = (i + j) / 2;
//		if (nums[mid] < target)
//		{
//			i = mid + 1;
//		}
//		else
//			j = mid;
//
//	}
//
//	if (nums[i] == target)
//		result[0] = i;
//	else
//		return result;
//
//	j = size - 1;
//	while (i < j)
//	{
//		mid = (i + j) / 2 + 1;
//		if (nums[mid] > target)
//			j = mid - 1;
//		else
//			i = mid;
//	}
//	result[1] = j;
//
//	return result;
//}
//
//int main(void)
//{
//	int a[] = {5, 7, 7, 8, 8, 10};
//	int target = 8;
//	int size = sizeof(a) / sizeof(int);
//	vector<int> vec(a, a + size);
//
//	vector<int> result = searchRange(vec, target);
//	for (auto val : result)
//	{
//		cout << val << endl;
//	}
//
//	system("pause");
//	return 0;
//}