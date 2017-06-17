//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int maxArea(vector<int>& height) {
//	int maxArea = 0;
//
//	//exhausted method
//	//for (vector<int>::iterator i = height.begin(); i != height.end(); ++i)
//	//{
//	//	for (vector<int>::iterator j = i + 1; j != height.end(); ++j)
//	//	{
//	//		if (min((int)*i, (int)*j) * (j - i) > maxArea)
//	//			maxArea = min((int)*i, (int)*j) * (j - i);
//	//	}
//	//}
//
//	int i = 0;
//	int j = height.size() - 1;
//
//	while (i < j)
//	{
//		int h = min(height.at(i), height.at(j));
//		maxArea = max(maxArea, h * (j - i));
//
//		while (height.at(i) <= h && i < j) ++i;
//		while (height.at(j) <= h && i < j) --j;
//	}
//
//	return maxArea;
//}
//
//int main(void)
//{
//	int a[] = {3, 5, 9, 6, 2, 4, 8, 7, 1, 2, 0};
//	vector<int> vec(a, a + 10);
//	cout << maxArea(vec) << endl;
//
//	system("pause");
//	return 0;
//}