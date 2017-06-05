#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
	vector<int> flagList = {0};
	int i = 0;
	for (auto val : flowerbed)
	{
		if (val == 1)
			flagList.push_back(i);

		++i;
	}

	int sum = 0;
	if (flagList.size() > 1)
	{
		for (int j = 1; j < flagList.size(); ++j)
		{
			if (flagList.at(j) - flagList.at(j - 1) != 0)
				sum += (flagList.at(j) - flagList.at(j - 1) - 1) / 2;
		}
	}
	
	if (sum == n)
		return true;

	return false;
}

int main()
{
	vector<int> vec = {1, 0, 0, 0, 1};
	int n = 1;

	if (canPlaceFlowers(vec, 1))
		cout << "True" << endl;

	cout << "False" << endl;

	system("pause");
	return 0;
}