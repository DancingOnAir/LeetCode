#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
int longestValidParentheses(string s) 
{
	if (s.size() < 2)
		return 0;
	int n = s.size();
	int i = 0;
	int j = 0;
	vector<char> record;

	while (i < n)
	{
		switch (s[i])
		{
		case '(':
			record.push_back(s[i]);
			break;
		case ')':
			if (record.size() != 0)
				record.pop_back();
			else
				++j;
			break;
		}

		++i;
	}

	return n - record.size() - j;
}

int main()
{
	string input = "(())";
	cout << longestValidParentheses(input) << endl;

	system("pause");
	return 0;
}