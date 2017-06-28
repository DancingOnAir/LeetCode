//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void nextPermutation(vector<int>& nums) 
//{
//	bool bFlag = false;
//	int size = nums.size();
//	if (size == 0 || size == 1)
//		return;
//
//	int iMark = size - 1;
//	int i, j;
//
//	for (i = size - 1; i >= 0; --i)
//	{
//		if (nums[iMark] > nums[i])
//		{
//			for (j = size - 1; j > 0; --j)
//			{
//				if (nums[j] > nums[i])
//				{
//					swap(nums[i], nums[j]);
//					break;
//				}
//			}
//				
//			sort(nums.begin() + i + 1, nums.end());
//			
//
//			bFlag = true;
//			break;
//		}
//		else
//		{
//			iMark = i;
//		}
//	}
//
//	if (!bFlag)
//		sort(nums.begin(), nums.end());
//}
//
//int main(void)
//{
//	int a[] = { 5, 4, 7, 5, 3, 2 };
//	int size = sizeof(a) / sizeof(int);
//	vector<int> vec(a, a + size);
//
//	nextPermutation(vec);
//
//	for (auto val : vec)
//	{
//		cout << val << endl;
//	}
//
//	system("pause");
//	return 0;
//}