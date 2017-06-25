//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//
//using namespace std;
//
//int removeDuplicates(vector<int>& nums) 
//{
//	for (vector<int>::iterator iter = nums.begin(); iter != nums.end();)
//	{
//		if (iter != nums.begin() && *iter == *(iter - 1))
//			iter = nums.erase(iter);
//		else
//			++iter;
//	}
//
//	return nums.size();
//}
//
//int main(void)
//{
//	int a[] = { 1, 1, 2 };
//	int size = sizeof(a) / sizeof(int);
//
//	vector<int> vec(a, a + size);
//
//	cout << removeDuplicates(vec) << endl;
//	system("pause");
//	return 0;
//}