#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

string frequencySort(string s)
{
    int len = s.size();
    if (len < 3)
        return s;

    unordered_map<char, int> count;
    for (char c : s)
    {
        ++count[c];
    }

    map<int, vector<char>, greater<int>> m;
    for (auto& iter : count)
    {
        m[iter.second].emplace_back(iter.first);
    }

    string res;
    for (auto& iter : m)
    {
        for (char c : iter.second)
        {
            res += string(iter.first, c);
        }
    }

    return res;
}

void testFrequencySort()
{
    string s1 = "tree";
    cout << frequencySort(s1) << endl;

    string s2 = "cccaaa";
    cout << frequencySort(s2) << endl;

    string s3 = "Aabb";
    cout << frequencySort(s3) << endl;
}

int main()
{
    testFrequencySort();

    getchar();
    return 0;
}