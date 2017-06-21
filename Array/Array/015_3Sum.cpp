//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<vector<int> > threeSum(vector<int>& nums) 
//{
//	vector<vector<int> > vvi;
//	vector<int> tempVec;
//	int rest = 0;
//	int size = nums.size();
//	
//	sort(nums.begin(), nums.end());
//
//	int j, k;
//	for(int i = 0; i + 2 < size; ++i )
//	{
//		if (nums.at(i) > 0)
//			break;
//
//		if (i > 0 && nums[i] == nums[i - 1])
//			continue;
//
//		rest = -nums.at(i);
//		j = i + 1;
//		k = size - 1;
//		while (j < k)
//		{
//			if (nums.at(j) + nums.at(k) == rest)
//			{
//				tempVec.push_back(nums.at(i));
//				tempVec.push_back(nums.at(j));
//				tempVec.push_back(nums.at(k));
//				vvi.push_back(tempVec);
//
//				tempVec.clear();
//				++j;
//				--k;
//				while (j < k && nums[j] == nums[j-1]) ++j;
//				while (j < k && nums[k] == nums[k+1]) --k;
//			}
//			else if (nums.at(j) + nums.at(k) > rest)
//			{
//				--k;
//			}
//			else
//				++j;
//		}
//	}
//
//	return vvi;
//}
//
//int main(void)
//{
//	int a[] = {0,0,0 };
//	int size = sizeof(a) / sizeof(int);
//
//	vector<int> vec(a, a + size);
//
//	vector<vector<int>> result;
//	result = threeSum(vec);
//
//	for (auto row : result)
//	{
//		for (auto col : row)
//		{
//			cout << col << ", ";
//		}
//
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}