#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
bool isValid(string s) 
{
	if (s.empty())
		return false;

	vector<char> v;

	for (decltype(s.size()) i = 0; i < s.size(); ++i)
	{
		if (0 == i && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
			return false;

		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			v.push_back(s[i]);
			continue;
		}

		if (v.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
			return false;

		if ((s[i] == ')' && v.back() == '(') || (s[i] == '}' && v.back() == '{') || (s[i] == ']' && v.back() == '['))
			v.pop_back();
		else
			return false;
	}

	if (0 == v.size())
		return true;

	return false;
}

int main()
{
	string s = "({})";
	cout << isValid(s) << endl;

	system("pause");
	return 0;
}