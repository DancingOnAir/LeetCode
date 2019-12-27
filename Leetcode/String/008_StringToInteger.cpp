//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <math.h>
//#include <cctype>
//#include <algorithm> 
//#include <functional> 
////#include <locale>
//
//using namespace std;
//
//// trim from start
//static inline std::string &ltrim(std::string &s) {
//	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
//		std::not1(std::ptr_fun<int, int>(std::isspace))));
//	return s;
//}
//
//// trim from end
//static inline std::string &rtrim(std::string &s) {
//	s.erase(std::find_if(s.rbegin(), s.rend(),
//		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
//	return s;
//}
//
//// trim from both ends
//static inline std::string &trim(std::string &s) {
//	return ltrim(rtrim(s));
//}
//
//int myAtoi(string str)
//{
//	int signal = 1;
//	int base = 0;
//	int i = 0, j = 0;
//
//	while (isspace(str[i]))
//	{
//		++i;
//	}
//	str = str.substr(i, str.size() - i);
//
//	for (decltype(str.size()) index = 0; index != str.size(); ++index)
//	{
//		if ('-' == str[index] && index == 0)
//		{
//			signal = -1;
//			continue;
//		}
//		else if ('+' == str[index] && index == 0)
//		{
//			signal = 1;
//			continue;
//		}
//			
//		if (isdigit(str[index]))
//		{
//			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && (str[index] - '0' > 7)))
//			{
//				if (signal == 1)
//					return INT_MAX;
//				else
//					return INT_MIN;
//			}
//
//			base = base * 10 + (str[index] - '0');
//
//		}
//		else
//			break;
//	}
//
//	return signal * base;
//}
//
//int my_atoi(std::string str)
//{
//    if (0 == str.size())
//        return 0;
//
//    bool isNegative = false;
//    int i = 0;
//    long long re = 0;
//
//    while (' ' == str[i])
//    {
//        ++i;
//    }
//
//    if ('-' == str[i] || '+' == str[i])
//    {
//        if ('-' == str[i])
//            isNegative = true;
//
//        ++i;
//    }
//
//    while (str[i] >= '0' && str[i] <= '9')
//    {
//        re = re * 10 + (str[i] - '0');
//
//        ++i;
//        if (re > INT_MAX)
//            return isNegative ? INT_MIN : INT_MAX;
//    }
//
//    return isNegative ? re * (-1) : re;
//}
//
//int main()
//{
//    string s = "    -45u0123";
//    cout << myAtoi(s) << endl;
//    cout << my_atoi(s) << endl;
//
//    system("pause");
//    return 0;
//}