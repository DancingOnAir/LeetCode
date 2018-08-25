//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
////method 1
//int lengthOfLongestSubstring1(string s) 
//{
//	int maxLength = 0;
//	int tempLength = 0;
//	int position = 0;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		for (int j = position; j < i; ++j)
//		{
//			if (s[i] == s[j])
//			{
//				if(tempLength > maxLength)
//					maxLength = tempLength;
//				
//				tempLength = tempLength -  (j + 1 - position);
//				position = j + 1;
//				break;
//			}
//				
//		}
//		++tempLength;
//	}
//
//	if (maxLength < tempLength)
//		maxLength = tempLength;
//	return maxLength;
//}
//
////method 2
//int lengthOfLongestSubstring(string s)
//{
//    if (0 == s.size())
//        return 0;
//
//    int maxLength = 0;
//    int pos = -1;
//    vector<int> vs(256, -1);
//
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (vs[s[i]] > pos)
//            pos = vs[s[i]];
//
//        vs[s[i]] = i;
//
//        maxLength = max(maxLength, i - pos);
//    }
//    
//    return maxLength;
//}
//
//int main(void)
//{
//    string a = "abcabcbb";
//    string b = "bbtablud";
//    string c = "pwwkew";
//
//    cout << lengthOfLongestSubstring(b) << endl;
//
//    system("pause");
//    return 0;
//}