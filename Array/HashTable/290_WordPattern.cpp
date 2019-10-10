#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string str)
{
    if (pattern.empty() || str.empty())
        return false;

    unordered_map<char, string> m;
    int startIndex = 0;

    for (char c : pattern)
    {
        string tmp("");
        for (int i = startIndex; i < str.size(); ++i)
        {
            if (str[i] == ' ')
            {
                tmp = str.substr(startIndex, i - startIndex);
                startIndex = i + 1;
                break;
            }
            else if (i == str.size() - 1)
            {
                tmp = str.substr(startIndex);
                startIndex = i + 1;
            }
        }

        if (tmp == "")
            return false;

        if (m.count(c))
        {
            if (m[c] != tmp)
                return false;
        }
        else
        {
            for (auto iter : m)
            {
                if (iter.second == tmp)
                    return false;
            }

            m[c] = tmp;
        }

    }

    return startIndex == str.size();
}

void testWordPattern()
{
    string pattern1 = "abba";
    string str1 = "dog cat cat dog";
    cout << (wordPattern(pattern1, str1) ? "True" : "False") << endl;

    string pattern2 = "abba";
    string str2 = "dog cat cat fish";
    cout << (wordPattern(pattern2, str2) ? "True" : "False") << endl;

    string pattern3 = "aaaa";
    string str3 = "dog cat cat dog";
    cout << (wordPattern(pattern3, str3) ? "True" : "False") << endl;

    string pattern4 = "abba";
    string str4 = "dog dog dog dog";
    cout << (wordPattern(pattern4, str4) ? "True" : "False") << endl;

    string pattern5 = "he";
    string str5 = "unit";
    cout << (wordPattern(pattern5, str5) ? "True" : "False") << endl;
}

int main()
{
    testWordPattern();

    getchar();
    return 0;
}