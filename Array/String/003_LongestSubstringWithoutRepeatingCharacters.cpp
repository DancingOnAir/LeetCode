#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
int lengthOfLongestSubstring(string s) 
{
	int maxLength = 0;
	int tempLength = 0;
	int position = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = position; j < i; ++j)
		{
			if (s[i] == s[j])
			{
				if(tempLength > maxLength)
					maxLength = tempLength;
				
				tempLength = tempLength -  (j + 1 - position);
				position = j + 1;
				break;
			}
				
		}
		++tempLength;
	}

	if (maxLength < tempLength)
		maxLength = tempLength;
	return maxLength;
}

int main(void)
{
	string a = "abcabcbb";
	string b = "bbtablud";
	string c = "pwwkew";

	cout << lengthOfLongestSubstring(b) << endl;

	system("pause");
	return 0;
}