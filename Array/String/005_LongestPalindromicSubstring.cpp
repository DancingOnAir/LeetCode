//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
////string longestPalindrome(string s) 
////{
////	vector<int> dict(256, -1);
////	int position = -1;
////	int end = -1;
////	int start = -1;
////	int maxLength = 0;
////	string result = "";
////
////	for (int i = 0; i < s.size(); ++i)
////	{
////		if (dict[s[i]] > position)
////		{
////			//if (i - end == 1 && start != -1)
////			//	start = position;
////			//else
////			//	start = dict[s[i]];
////			position = dict[s[i]];
////			end = i;
////		}
////
////		dict[s[i]] = i;
////		maxLength = max(maxLength, end - position);
////	}
////
////	if (position == -1)
////		return s;
////
////	result = s.substr(position, maxLength + 1);
////	return result;
////}
//
//string longestPalindrome(string s)
//{
//	if (s.empty()) return "";
//	if (s.size() == 1) return s;
//	int min_start = 0, max_len = 1;
//	for (int i = 0; i < s.size();) {
//		int j = i, k = i;
//		while (k < s.size() - 1 && s[k + 1] == s[k]) 
//			++k; // Skip duplicate characters.
//		i = k + 1;
//		while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) 
//		{	
//			++k; 
//			--j; 
//		} // Expand.
//		int new_len = k - j + 1;
//		if (new_len > max_len) 
//		{ min_start = j; max_len = new_len; }
//	}
//	return s.substr(min_start, max_len);
//}
//
//int main(void)
//{
//	string s = "abba";
//
//	string result = longestPalindrome(s);
//
//	cout << result << endl;
//	system("pause");
//	return 0;
//}