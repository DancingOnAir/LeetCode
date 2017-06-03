#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int input[10000];

int partition(int* p, int start, int end)
{
	int left = start;
	int right = end - 1;

	int mid = p[end];

	while (left <= right)
	{
		while (p[left] < mid)  ++left;
		while (p[right] > mid) --right;

		if (left <= right)
		{
			swap(p[left], p[right]);
		}
	}

	if (p[left] < mid)
		left++;
	else
		swap(p[left], p[end]);

	return left;
}

void quickSortRecursive(int* p, int start, int end)
{

	int mid = partition(p, start, end);

	if (start < mid -1)
		quickSortRecursive(p, start, mid - 1);
	if (mid < end)
		quickSortRecursive(p, mid + 1, end);
}

void quickSort(int* p, int size)
{
	quickSortRecursive(p, 0, size - 1);
}

int calculateShortestSubarray(int* sortedArray, int* originalArray, int size)
{
	int pos = 0;
	int left = 0;
	int right = 0;

	for (int i = 0; i < size; ++i)
	{
		if (sortedArray[i] == originalArray[i])
			pos = i;

		if (sortedArray[i] != originalArray[i] && i >= pos)
		{
			left = pos;
			break;
		}
	}

	for (int j = size - 1; j >= 0; --j)
	{
		if (sortedArray[j] == originalArray[j])
			pos = j;

		if (sortedArray[j] != originalArray[j] && j <= pos)
		{
			right = pos;
			break;
		}	
	}

	if (left == size - 1)
		return size;
	else
		return right - left - 1;
}

int findUnsortedSubarray(vector<int>& nums)
{
	int size = nums.size();

	vector<int> copy(nums);

	quickSort(nums, size);
	return calculateShortestSubarray(nums, copy, size);
}

int main()
{
	vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
	
	int subSize = findUnsortedSubarray(nums);

	cout << subSize << endl;

	//for (int i = 0; i < nums.size(); ++i)
	//{
	//	cout << a[i] << " ";
	//}
	for (auto num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	system("pause");

	delete b;
	return 0;
}