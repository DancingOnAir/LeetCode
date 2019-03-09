#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

bool helper(string& s, set<string>& dict, string& res, int& pos)
{
    if (pos == s.size())
        return true;

    for (int i = 1; pos + i <= s.size(); ++i)
    {
        string temp = s.substr(pos, i);
        if (dict.find(s.substr(pos, i)) != dict.end())
        {
            res += " " + s.substr(pos, i);
            pos += i;

            return helper(s, dict, res, pos);
        }
    }

    return false;
}

unordered_map<string, vector<string>> cache;

bool containsSuffix(set<string> dict, string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (dict.find(str.substr(i)) != dict.end()) 
            return true;
    }

    return false;
}

vector<string> wordBreak(string s, vector<string>& wordDict)
{
    if (cache.count(s))
        return cache[s];

    set<string> dict;
    for (auto& word : wordDict)
        dict.insert(word);

    vector<string> res;
    if (dict.find(s) != dict.end())
        res.emplace_back(s);

    for (int i = 1; i < s.size(); ++i)
    {
        string left = s.substr(0, i);
        string right = s.substr(i);

        if (dict.find(left) != dict.end() && containsSuffix(dict, right))
        {
            for (string& ss : wordBreak(right, wordDict))
            {
                res.emplace_back(left + " " + ss);
            }
        }
    }

    cache.insert(make_pair(s, res));
    return res;
}

void testWordBreak()
{
    string s = "catsanddog";
    vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };

    auto res = wordBreak(s, wordDict);

    for (auto& str : res)
        cout << str << endl;
}

int main()
{
    testWordBreak();

    getchar();
    return 0;
}