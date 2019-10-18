#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

string frequencySort2(string s)
{
    int len = s.size();
    if (len < 3)
        return s;

    unordered_map<char, int> count;
    for (char c : s)
    {
        ++count[c];
    }

    vector<string> bucket(len + 1, "");
    for (auto& iter : count)
    {
        bucket[iter.second].append(string(iter.second, iter.first));
    }

    string res;
    for (int i = len; i > 0; --i)
    {
        res += bucket[i];
    }

    return res;
}

string frequencySort(string s)
{
    unordered_map<char, int> count;
    for (char c : s)
        ++count[c];

    sort(s.begin(), s.end(), [&](char a, char b) {
        if (count[a] > count[b])
            return true;
        if (count[a] == count[b])
            return a < b;
        return false;
    });

    return s;
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