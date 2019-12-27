//#include <iostream>
//#include <stdlib.h>
//#include <string>
//
//using namespace std;
//bool isMatch(string s, string p)
//{
//	if (p.empty())    
//		return s.empty();
//
//	if ('*' == p[1])
//		return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
//	else
//		return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
//}
////bool isMatch(string s, string p) 
////{
////	if (s.size() > p.size())
////		return false;
////
////	auto sb = s.begin(), se = s.end();
////	auto pb = p.begin(), pe = p.end();
////	int count = 0;
////
////	for (decltype(p.size()) i = 0; i < p.size(); ++i)
////	{
////		if (i != 0 && p[i-1] == '.' && p[i] == '*')
////			p[i] = '.';
////	}
////
////	while (sb != se)
////	{
////		while (pb != pe)
////		{
////			if (*pb == *sb || *pb == '.')
////			{
////				if (pe - pb < s.size())
////					return false;
////				else
////				{
////					for (decltype(s.size()) i = 0; i < s.size(); ++i)
////					{
////						if (*(pb + i) == *(sb + i) || 
////							*(pb + i) == '.' || 
////							(*(pb + i) == '*' && *(sb + i) == *(sb + i - 1)))
////						{
////							++count;
////						}
////						else
////						{
////							count = 0;
////							break;
////						}
////					}
////
////					if (count == s.size())
////						return true;
////				}
////			}
////			++pb;
////		}
////
////		++sb;
////	}
////
////	if(count == s.size())
////		return true;
////
////	return false;
////}
//
//int main()
//{
//	string s = "aab";
//	string p = "c*a*b";
//
//	cout << isMatch(s, p) << endl;
//	//string str = "We think in generalities, but we live in details.";
//	//string s1 = str.substr(3, 5);
//	//string s2 = str.substr(2, 5);
//	//string s3 = str.substr(1, 5);
//	//string s4 = str.substr(0, 5);
//
//	//cout << s1 << endl;
//	//cout << s2 << endl;
//	//cout << s3 << endl;
//	//cout << s4 << endl;
//
//	system("pause");
//	return 0;
//}