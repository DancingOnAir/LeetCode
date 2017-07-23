//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> letterCombinations(string digits)
//{
//	if (digits.empty()) 
//		return vector<string>();
//
//	vector<string> vec = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//	vector<string> result(1, "");
//
//	for (auto d : digits)
//	{
//		int iVal = d - '0';
//		if (iVal >= 0 && iVal <= 9)
//		{
//			string candidate = vec[iVal];
//			if (candidate.empty())
//				continue;
//
//			vector<string> temp;
//			for (decltype(candidate.size()) j = 0; j < candidate.size(); ++j)
//				for (decltype(result.size()) k = 0; k < result.size(); ++k)
//					temp.push_back(result[k] + candidate[j]);
//			
//			result.swap(temp);
//		}
//		else
//			break;
//	}
//
//	return result;
//}
//
//int main(void)
//{
//	string digits = "234";
//
//	vector<string> result = letterCombinations(digits);
//
//	for (auto val : result)
//		cout << val << ", ";
//
//	cout << endl;
//
//	system("pause");
//	return 0;
//}