#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
int searchInsert(vector<int>& nums, int target) 
{
	int i = 0;
	int j = nums.size() - 1;

	while (i < j)
	{
		int mid = (i + j) / 2;
		if (nums[mid] < target)
			i = mid + 1;
		else
			j = mid;
	}

	if (nums[i] >= target)
		return i;
	else
		return i + 1;
}

int main(void)
{
	int a[] = { 1, 3, 5, 6 };
	int target = 0;
	vector<int> vec(a, a + 4);

	cout << searchInsert(vec, target) << endl;

	system("pause");
	return 0;
}