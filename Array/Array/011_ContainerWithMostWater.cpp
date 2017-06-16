#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
	int maxArea = 0;

	//exhausted method
	//for (vector<int>::iterator i = height.begin(); i != height.end(); ++i)
	//{
	//	for (vector<int>::iterator j = i + 1; j != height.end(); ++j)
	//	{
	//		if (min((int)*i, (int)*j) * (j - i) > maxArea)
	//			maxArea = min((int)*i, (int)*j) * (j - i);
	//	}
	//}

	sort(height.begin(), height.end());
	int size = height.size();

	for (int i = 0; i < size; ++i)
	{
		if (maxArea < height.at(i) * (size - i - 1))
			maxArea = height.at(i) * (size - i - 1);
	}

	return maxArea;
}

int main(void)
{
	int a[] = {3, 5, 9, 6, 2, 4, 8, 7, 1, 2, 0};
	vector<int> vec(a, a + 10);
	cout << maxArea(vec) << endl;

	system("pause");
	return 0;
}