//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <vector>
//
//using namespace std;
////vector<string> generateParenthesis(int n) 
////{
////	if (0 >= n)
////		return vector<string>();
////
////	string v = "()";
////	vector<string> result(1, "");
////	string origin = "";
////
////	for (int i = 0; i < n; ++i)
////	{
////		origin += v;
////	}
////	result.push_back(origin);
////
////	for (decltype(origin.size()) i = 0; i < origin.size(); ++i)
////	{
////		if (')' == origin[i] && i != origin.size() - 1)
////		{
////			for (decltype(origin.size()) j = i; j < origin.size() - 1; ++j)
////			{
////				string copy = origin;
////				char temp = copy[j + 1];
////				copy[j + 1] = copy[i];
////				copy[i] = temp;
////
////				result.push_back(copy);
////			}
////		}
////		else
////			continue;
////	}
////	return result;
////}
//void recursiveAdd(vector<string>& result, string s, int open, int close, int n)
//{
//	if (s.size() == n * 2)
//	{
//		result.push_back(s);
//		return;
//	}
//
//	if (open < n)
//		recursiveAdd(result, s + "(", open + 1, close, n);
//	if (close < open)
//		recursiveAdd(result, s + ")", open, close + 1, n);
//}
//
//vector<string> generateParenthesis(int n)
//{
//	vector<string> result;
//	recursiveAdd(result, "", 0, 0, n);
//
//	return result;
//}
//
//int main()
//{
//	int n = 3;
//	vector<string> result;
//
//	result = generateParenthesis(n);
//	for (auto val : result)
//		cout << val << endl;
//
//	system("pause");
//	return 0;
//}