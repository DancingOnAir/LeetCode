//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//
//using namespace std;
//
//vector<int> twoSum(vector<int>& nums, int target) {
//
//	cout << target << endl;
//
//	vector<int> tempVec;
//	int number = 0;
//
//
//		
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		number = target - nums.at(i);
//		for (int j = 0; j < nums.size(); ++j)
//		{
//			if (nums.at(j) == number && j != i)
//			{
//				tempVec.push_back(i);
//				tempVec.push_back(j);
//
//				return tempVec;
//			}
//		}
//	}
//
//
//	return tempVec;
//}
//
//int main(void)
//{
//	int pArray[4] = { 2, 7, 11, 15 };
//	vector<int> vec(pArray, pArray + 4);
//
//	//twoSum(vec, vec.at(0) + vec.at(1));
//
//	for (auto value : twoSum(vec, vec.at(0) + vec.at(1)))
//	{
//		cout << value << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}