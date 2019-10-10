#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

bool wordPattern2(string pattern, string str)
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

bool wordPattern(string pattern, string str)
{
    istringstream iss(str);
    vector<string> vs;
    string tmp("");
    while (iss >> tmp)
    {
        vs.emplace_back(tmp);
    }

    if (vs.size() != pattern.size())
        return false;

    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;

    for (int i = 0; i < vs.size(); ++i)
    {
        if (!s2c.count(vs[i]) && !c2s.count(pattern[i]))
        {
            s2c[vs[i]] = pattern[i];
            c2s[pattern[i]] = vs[i];
            continue;
        }

        if (s2c[vs[i]] != pattern[i])
            return false;
    }

    return true;
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