//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
////solution 1
////int longestValidParentheses(string s) 
////{
////	if (s.size() < 2)
////		return 0;
////	int n = s.size();
////	int i = 0;
////	int j = 0;
////	vector<char> record;
////
////	while (i < n)
////	{
////		switch (s[i])
////		{
////		case '(':
////			record.push_back(s[i]);
////			break;
////		case ')':
////			if (record.size() != 0)
////				record.pop_back();
////			else
////				++j;
////			break;
////		}
////
////		++i;
////	}
////
////	return n - record.size() - j;
////}
//
//int longestValidParentheses(string s)
//{
//	stack<int> stk;
//	stk.push(-1);
//	int maxL = 0;
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		int temp = stk.top();
//		if (temp != -1 && s[i] == ')' && s[temp] == '(')
//		{
//			stk.pop();
//			maxL = max(maxL, i - stk.top());
//		}
//		else
//			stk.push(i);
//	}
//	return maxL;
//}
//
//int main()
//{
//	string input = "(())";
//	cout << longestValidParentheses(input) << endl;
//
//	system("pause");
//	return 0;
//}