#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	vector<int> tempVec;
	int rest, i, j, k, l;
	int size = nums.size();

	sort(nums.begin(), nums.end());

	for (i = 0; i < size; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		for (j = i + 1; j < size - 2; ++j)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;

			rest = target - nums[i] - nums[j];
			k = j + 1;
			l = size - 1;

			while (k < l)
			{
				if (nums[k] + nums[l] == rest)
				{
					//update
					tempVec.push_back(nums[i]);
					tempVec.push_back(nums[j]);
					tempVec.push_back(nums[k]);
					tempVec.push_back(nums[l]);
					result.push_back(tempVec);
					tempVec.clear();

					++k;
					--l;

					while (k < l && nums[k] == nums[k - 1]) ++k;
					while (k < l && nums[l] == nums[l + 1])	--l;
				}
				else if (nums[k] + nums[l] < rest)
				{
					++k;
				}
				else
				{
					--l;
				}
			}
		}
	}


	return result;
}

int main(void)
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
	int target = -1;
	int size = sizeof(a) / sizeof(int);
	vector<int> vec(a, a + size);

	vector<vector<int>> result = fourSum(vec, target);

	for (auto row : result)
	{
		for (auto col : row)
		{
			cout << col << ",";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}