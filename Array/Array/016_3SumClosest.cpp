#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) 
{
	int size = nums.size();
	if (size < 3)
		return 0;

	int sum = 0;
	int j, k;

	sort(nums.begin(), nums.end());
	sum = nums[0] + nums[1] + nums[2];

	for (int i = 0; i < size - 2; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		j = i + 1;
		k = size - 1;
		
		while (j < k)
		{
			int tempSum = nums[i] + nums[j] + nums[k];
			if (tempSum == target)
				return target;
			if (abs(tempSum - target) < abs(sum - target))
			{
				sum = tempSum;
			}
			if (tempSum > target)
				--k;
			else
				++j;
		}
	}

	return sum;
}

int main(void)
{
	int a[] = {-1, 2, 1, -4};
	int size = sizeof(a) / sizeof(int);
	int target = 1;

	vector<int> vec(a, a + size);
	cout <<	threeSumClosest(vec, target) << endl;

	system("pause");
	return 0;
}