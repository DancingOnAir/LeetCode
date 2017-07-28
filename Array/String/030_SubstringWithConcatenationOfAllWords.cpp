#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
bool isMatch(string s, vector<string> words, int sizeOfWord)
{
	if (words.empty() && s.empty())
		return true;

	vector<string> temp = words;
	for (decltype(s.size()) i = 0; i != s.size(); i = i + sizeOfWord)
	{
		for (decltype(words.size()) j = 0; j != words.size(); ++j)
		{
			if (words[j] == s.substr(i, sizeOfWord))
			{
				temp.erase(temp.begin() + j);
				if (isMatch(s.substr(sizeOfWord), temp, sizeOfWord))
					return true;
			}
		}
	}

	return false;
}

vector<int> findSubstring(string s, vector<string>& words) 
{
	vector<int> result;
	if (0 == words.size())
		return result;

	int sizeOfWord = words[0].size();
	int lengthOfWords = sizeOfWord * words.size();
	for (decltype(s.size()) i = 0; i != s.size(); i = i + sizeOfWord)
	{
		if (isMatch(s.substr(i, lengthOfWords), words, sizeOfWord))
			result.push_back(i);
	}

	return result;
}

int main(void)
{
	string s = "barfoofoobarthefoobarman";
	vector<string> input = { "foo", "bar", "the" };
	vector<int> result = findSubstring(s, input);

	for (auto r : result)
		cout << r << endl;

	system("pause");
	return 0;
}