#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) 
{
	vector<vector<int> > vvi;

	int rest = 0;
	int last = 0;

	bool repeat = false;
	int size = nums.size();
	vector<int> tempVec;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < size; ++i )
	{
		rest = -nums.at(i);
		for (int j = i + 1; j < size; ++j)
		{
			last = rest - nums.at(j);
			if (last < nums.at(j))
				continue;

			for (int k = j + 1; k < size; ++k)
			{
				if (nums.at(k) > last)
					break;

				if (last == nums.at(k))
				{
					repeat = false;
					tempVec.push_back(nums.at(i));
					tempVec.push_back(nums.at(j));
					tempVec.push_back(nums.at(k));

					sort(tempVec.begin(), tempVec.end());

					for (auto row : vvi)
					{
						if (row == tempVec)
							repeat = true;
					}

					if (repeat == false)
						vvi.push_back(tempVec);

					tempVec.clear();
				}
			}
		}
	}

	return vvi;
}

int main(void)
{
	int a[] = { 9,-4,-5,8,-5,7,5,-6,-4,-13,9,-10,-13,-6,2,-15,-13,-9,-4,-13,-9,-9,13,-13,-9,9,-15,1,0,-14,-8,-13,-11,-5,2,0,9,14,9,-9,8,-5,-12,10,-3,5,3,-1,12,14,1,10,12,-1,13,-12,-14,13,4,-7,6,4,-5,11,6,4,-12,0,3,4,-2,-3,7,1,14,-11,-8,2,-5,11,-7,3,6,-9,9,4,-14,10,-6,-2,-11,-14,-13,-9,4,0,11,-1,-15,-9,-12,-1,3,10,7,-5,6,6,12,8,2,-9,-4,-6,-11,-9,5,-10,-14,-15,3 };
	int size = sizeof(a) / sizeof(int);

	vector<int> vec(a, a + size);

	vector<vector<int>> result;
	result = threeSum(vec);

	for (auto row : result)
	{
		for (auto col : row)
		{
			cout << col << ", ";
		}

		cout << endl;
	}

	system("pause");
	return 0;
}