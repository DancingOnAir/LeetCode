//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
////method 1
////int lengthOfLongestSubstring(string s) 
////{
////	int maxLength = 0;
////	int tempLength = 0;
////	int position = 0;
////	for (int i = 0; i < s.size(); ++i)
////	{
////		for (int j = position; j < i; ++j)
////		{
////			if (s[i] == s[j])
////			{
////				if(tempLength > maxLength)
////					maxLength = tempLength;
////				
////				tempLength = tempLength -  (j + 1 - position);
////				position = j + 1;
////				break;
////			}
////				
////		}
////		++tempLength;
////	}
////
////	if (maxLength < tempLength)
////		maxLength = tempLength;
////	return maxLength;
////}
//
////method 2
//int lengthOfLongestSubstring(string s)
//{
//	int maxLength = 0;
//	int position = -1;
//	vector<int> vec(256, -1);
//
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (vec[s[i]] > position)
//		{
//			position = vec[s[i]];
//		}
//		vec[s[i]] = i;
//
//		maxLength = max(maxLength, i - position);
//	}
//
//
//	return maxLength;
//}
//
//int main(void)
//{
//	string a = "abcabcbb";
//	string b = "bbtablud";
//	string c = "pwwkew";
//
//	cout << lengthOfLongestSubstring(b) << endl;
//
//	system("pause");
//	return 0;
//}