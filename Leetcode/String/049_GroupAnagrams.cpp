#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams1(vector<string>& strs)
{
    vector<vector<string>> res;
    if (strs.empty())
        return res;

    map<vector<int>, vector<string>> m;
    for (int i = 0; i < strs.size(); ++i)
    {
        vector<int> characters(26);
        for (char c : strs[i])
        {
            characters[c - 'a']++;
        }

        m[characters].emplace_back(strs[i]);
    }

    for (auto str : m)
    {
        res.emplace_back(str.second);
    }

    return res;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> res;
    if (strs.empty())
        return res;

    unordered_map<string, vector<string>> m;
    for (auto& str : strs)
    {
        string temp = str;
        sort(temp.begin(), temp.end());

        m[temp].emplace_back(str);
    }

    for (auto& iter : m)
    {
        res.emplace_back(iter.second);
    }

    return res;
}

void testGroupAnagrams()
{
    vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
    auto res = groupAnagrams(strs);

    for (auto& row : res)
    {
        for (auto& col : row)
        {
            cout << col << ", ";
        }
        cout << endl;
    }
}

int main()
{
    testGroupAnagrams();

    getchar();
    return 0;
}
