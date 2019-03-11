#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

//unordered_map<string, vector<string>> cache;
//
//bool containsSuffix(set<string> dict, string str)
//{
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (dict.find(str.substr(i)) != dict.end()) 
//            return true;
//    }
//
//    return false;
//}
//
//vector<string> wordBreak(string s, vector<string>& wordDict)
//{
//    if (cache.count(s))
//        return cache[s];
//
//    set<string> dict;
//    for (auto& word : wordDict)
//        dict.insert(word);
//
//    vector<string> res;
//    if (dict.find(s) != dict.end())
//        res.emplace_back(s);
//
//    for (int i = 1; i < s.size(); ++i)
//    {
//        string left = s.substr(0, i);
//        string right = s.substr(i);
//
//        if (dict.find(left) != dict.end() && containsSuffix(dict, right))
//        {
//            for (string& ss : wordBreak(right, wordDict))
//            {
//                res.emplace_back(left + " " + ss);
//            }
//        }
//    }
//
//    cache.insert(make_pair(s, res));
//    return res;
//}

void buildPath(vector<bool>& isBreakable, string& s, int pos, vector<string>& res, string cur, unordered_set<string>& dict, int minLen, int maxLen)
{
    int i = 0, n = s.size();
    for (i = minLen; i <= min(maxLen, n - pos); ++i)
    {
        if (isBreakable[pos + i] && dict.count(s.substr(pos, i)))
        {
            if (pos + i == n)
                res.emplace_back(cur + s.substr(pos, i));
            else
                buildPath(isBreakable, s, pos + i, res, cur + s.substr(pos, i) + " ", dict, minLen, maxLen);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict)
{
    int n = s.size();
    int minLen = INT_MAX, maxLen = INT_MIN;
    int i = 0, len = 0;

    unordered_set<string> dict;
    for (auto& word : wordDict)
    {
        dict.insert(word);
        minLen = min(minLen, (int)word.size());
        maxLen = max(maxLen, (int)word.size());
    }

    vector<bool> isBreakable(n + 1, false);

    for (i = n - minLen, isBreakable[n] = true; i >= 0; --i)
    {
        for (len = minLen; len <= min(maxLen, n - i); ++len)
        {
            if (isBreakable[i + len] && dict.count(s.substr(i, len)))
            {
                isBreakable[i] = true;
                break;
            }
        }
    }

    vector<string> res;
    if (isBreakable[0])
        buildPath(isBreakable, s, 0, res, "", dict, minLen, maxLen);

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