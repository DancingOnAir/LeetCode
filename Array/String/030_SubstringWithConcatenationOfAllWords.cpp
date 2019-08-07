#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


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

vector<int> findSubstring2(string s, vector<string>& words) 
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

bool isTraversed(unordered_map<string, int>& m)
{
    for (auto x : m)
    {
        if (x.second)
            return false;
    }

    return true;
}

vector<int> findSubstring3(string s, vector<string>& words)
{
    vector<int> res;
    if (s.empty() || words.empty())
        return res;

    int s1 = words.size();
    int s2 = words[0].size();
    int s3 = s.size();
    unordered_map<string, int> m, n;
    for (auto& word : words)
    {
        m[word]++;
    }

    int pos = 0;
    while (pos < s3 - s2)
    {
        if (m.count(s.substr(pos, s2)))
        {
            int tempPos = pos;
            n = m;
            while (tempPos < s3)
            {
                string tempStr = s.substr(tempPos, s2);
                if (n.count(tempStr) && n[tempStr] > 0)
                {
                    n[tempStr]--;
                    tempPos += s2;
                    if (isTraversed(n))
                    {
                        res.emplace_back(pos);
                        break;
                    }

                }
                else
                    break;
            }
        }

        ++pos;
    }

    return res;
}

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> indexes;
    if (s.empty() || words.empty())
        return indexes;

    unordered_map<string, int> counts;
    for (string word : words)
        counts[word]++;

    int n = s.length(), num = words.size(), len = words[0].length();


    for (int i = 0; i < n - num * len + 1; i++) {
        unordered_map<string, int> seen;
        int j = 0;

        for (; j < num; j++)
        {
            string word = s.substr(i + j * len, len);
            if (counts.count(word))
            {
                seen[word]++;
                if (seen[word] > counts[word])
                    break;
            }
            else
                break;
        }

        if (j == num)
            indexes.push_back(i);
    }
    return indexes;
}

void display(vector<int>& nums)
{
    if (nums.empty())
        return;

    for (int x : nums)
        cout << x << ", ";
    cout << endl;
}

void testFindSubstring()
{
    string s1 = "barfoothefoobarman";
    vector<string> input1 = { "foo", "bar", "the" };
    vector<int> result1 = findSubstring(s1, input1);
    display(result1);

    string s2 = "wordgoodgoodgoodbestword";
    vector<string> input2 = { "word", "good", "best", "word" };
    vector<int> result2 = findSubstring(s2, input2);
    display(result2);

    cout << "done" << endl;
}

int main(void)
{
    testFindSubstring();
    getchar();
    return 0;
}