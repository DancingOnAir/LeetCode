//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<vector<int>> result;
//vector<int> combination;
//
//void recusiveSum(vector<int>& candidates, int target, int position)
//{
//	if (target == 0)
//	{
//		result.push_back(combination);
//		return;
//	}
//	int size = candidates.size();
//
//	for (int i = position; i < size; ++i)
//	{
//		if (candidates[i] <= target)
//		{
//			combination.push_back(candidates[i]);
//			recusiveSum(candidates, target - candidates[i], i);
//			combination.pop_back();
//		}
//		else if (candidates[i] > target)
//			return;
//	}
//}
//
//vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
//{
//	sort(candidates.begin(), candidates.end());
//
//	recusiveSum(candidates, target, 0);
//
//	return result;
//}
//
//int main()
//{
//	int a[] = { 2, 3, 6, 7 };
//	int target = 7;
//	vector<int> vec(a, a + 4);
//
//	vector<vector<int> > b = combinationSum(vec, target);
//
//	for (auto row : b)
//	{
//		for (auto col : row)
//		{
//			cout << col << ",";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}