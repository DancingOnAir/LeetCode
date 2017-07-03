#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> result;
vector<int> combination;

void recursiveSum2(vector<int>& candidates, int target, int position)
{
	if (target == 0)
	{
		for (auto val : result)
		{
			if (val == combination)
				return;
		}

		result.push_back(combination);
		return;
	}

	for (int i = position; i < candidates.size(); ++i)
	{

		if (candidates[i] <= target)
		{
			combination.push_back(candidates[i]);
			recursiveSum2(candidates, target - candidates[i], i + 1);
			combination.pop_back();
		}
		else
		{
			return;
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
	sort(candidates.begin(), candidates.end());
	recursiveSum2(candidates, target, 0);

	return result;
}

int main(void)
{
	int target = 8;
	int a[] = { 10, 1, 2, 7, 6, 1, 5 };
	vector<int> vec(a, a + 7);
	vector<vector<int>> rec;
	rec = combinationSum2(vec, target);

	for (auto row : rec)
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