//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	double median = 0;
//
//	nums1.insert(nums1.end(), nums2.begin(), nums2.end());
//	
//	int size = nums1.size();
//	if (size % 2 != 0)
//	{	
//
//		nth_element(nums1.begin(), nums1.begin() + size / 2, nums1.end());
//		median = nums1.at(size / 2);
//	}
//	else
//	{
//		nth_element(nums1.begin(), nums1.begin() + size / 2 - 1, nums1.end());
//		median = nums1.at(size / 2 - 1);
//		nth_element(nums1.begin(), nums1.begin() + size / 2, nums1.end());
//		median = (median + nums1.at(size / 2))/2;
//	}
//
//	return median;
//}
//
//int main(void)
//{
//	int a[] = { 1, 2 };
//	int b[] = { 3, 4};
//	vector<int> nums1(a, a + 2);
//	vector<int> nums2(b, b + 2);
//
//	cout << findMedianSortedArrays(nums1, nums2) << endl;
//
//	system("pause");
//
//	return 0;
//}