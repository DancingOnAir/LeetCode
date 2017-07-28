//#include <iostream>
//#include <stdlib.h>
//#include <string>
//
//using namespace std;
//int strStr(string haystack, string needle) 
//{
//	int result = -1;
//
//	if (haystack.size() < needle.size())
//		return result;
//
//	if (needle.empty())
//		return 0;
//
//	for (decltype(haystack.size()) i = 0; i != haystack.size(); ++i)
//	{
//		if (haystack[i] == needle[0])
//		{
//			for (decltype(needle.size()) j = 0; j != needle.size(); ++j)
//			{
//				if (needle[j] != haystack[j + i])
//					break;
//				else if (j == needle.size() - 1)
//					return i;
//			}
//		}
//	}
//
//	return result;
//}
//
//int main()
//{
//	string needle = "hi";
//	string haystack = "abv hiasd";
//
//	cout << strStr(haystack, needle) << endl;
//	system("pause");
//	return 0;
//}