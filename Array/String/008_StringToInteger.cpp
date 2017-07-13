#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <cctype>
#include <algorithm> 
#include <functional> 
//#include <locale>

using namespace std;

// trim from start
static inline std::string &ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

int myAtoi(string str) 
{
	int result = 0;
	bool isPostive = true;

	if (str.length() == 0)
		return result;
	
	str = trim(str);

	for (decltype(str.size()) i = 0; i != str.size(); ++i)
	{
		if (str[i] == '-' && i == 0)
		{
			isPostive = false;
			continue;
		}
		else if (str[i] == '+' && i == 0)
		{
			isPostive = true;
			continue;
		}
		

		if (isPostive == true && (result >  INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7))) {
			return INT_MAX;
		}

		if (isPostive == false && (result >  INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 8))) {
			return INT_MIN;
		}

		if (isdigit(str[i]))
		{
			result = (str[i] - '0') + result * 10;
		}
		else
			break;
			
	}

	if (!isPostive)
		result = -1 * result;

	return result;
}

int main()
{
	string s = "-1010023630o4";
	cout << myAtoi(s) << endl;

	system("pause");
	return 0;
}