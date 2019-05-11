#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

void backtracking(vector<string>& res, vector<string>& words, int& count, int& idx, string& remainder)
{
    if (count >= 2 && remainder == "")
    {
        res.emplace_back(words[idx]);
        count = 0;

        return;
    }

    for (int i = 0; i < idx; ++i)
    {
        if (words[i].size() > remainder.size())
            return;

        if (remainder.substr(0, words[i].size()) == words[i])
            backtracking(res, words, ++count, idx, remainder.substr(words[i].size()));
    }
}

bool isConcatenated(const string& word, unordered_set<string>& dict, int minLen)
{
    if (dict.count(word))
        return true;

    for (int i = minLen; i < word.size() - minLen + 1; ++i)
    {
        if (dict.count(word.substr(0, i)) > 0 && isConcatenated(word.substr(i, word.size() - i), dict, minLen))
            return true;
    }

    return false;
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
{
    if (words.size() < 2)
        return vector<string>();

    sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
    vector<string> res;
    unordered_set<string> dict;
    int minLen = words.front().size();

    for (int i = 0; i < words.size(); dict.insert(words[i++]))
    {
        if (words[i].size() >= minLen * 2 && isConcatenated(words[i], dict, minLen))
        {
            res.emplace_back(words[i]);
        }
    }

    return res;
}

void testFindAllConcatenatedWordsInADict()
{
    vector<string> words{ "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
    auto res = findAllConcatenatedWordsInADict(words);

    for (string s : res)
    {
        cout << s << ", ";
    }
    cout << endl;
}

int main()
{
    testFindAllConcatenatedWordsInADict();

    getchar();
    return 0;
}