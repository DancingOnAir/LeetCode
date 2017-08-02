#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
string recursiveCountAndSay(int n, string s)
{
	if (1 == n)
		return s;

	if ("1" == s && 1 == n)
		return s;

	if ("1" == s && 1 != n)
		return recursiveCountAndSay(n - 1, "11");

	int count = 1;
	int number = 0;
	string temp = "";

	for (decltype(s.size()) i = 1; i != s.size(); ++i)
	{
		if (i == s.size() - 1)
		{
			if (s[i] != s[i - 1])
			{
				temp += to_string(count) + string(1, s[i - 1]);
				temp += "1" + string(1, s[i]);
			}
			else
			{
				++count;
				temp += to_string(count) + string(1, s[i]);
			}
		}
		else
		{
			if (s[i] != s[i - 1])
			{
				temp += to_string(count) + string(1, s[i - 1]);
				count = 1;
			}
			else
				++count;
		}
	}

	--n;
	return recursiveCountAndSay(n, temp);
}

string countAndSay(int n) 
{
	if (0 == n)
		return 0;

	string start = "1";
	return recursiveCountAndSay(n, start);
}

int main()
{
	
	int input = 4;
	cout << countAndSay(input) << endl;

	system("pause");
	return 0;
}