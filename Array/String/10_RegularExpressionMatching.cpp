#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

bool isMatch(string s, string p) 
{
	for (auto b = s.begin(), e = s.end(); b != e; ++b)
	{
		for (auto c : p)
		{
			if (c == *b || c == '*')
			{

			}
		}
	}
	return true;
}

int main()
{
	string s = "aa";
	string p = "a*";

	cout << isMatch(s, p) << endl;

	system("pause");
	return 0;
}