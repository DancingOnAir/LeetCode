#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram2(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> vs(128), vt(128);
    for (int i = 0; i < s.size(); ++i)
    {
        ++vs[s[i]];
        ++vt[t[i]];
    }

    return vs == vt;
}

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> v(26);
    for (int i = 0; i < s.size(); ++i)
    {
        ++v[s[i] - 'a'];
        --v[t[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i)
    {
        if (v[i] != 0)
            return false;
    }
    return true;
}

void testIsAnagram()
{
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << (isAnagram(s1, t1) ? "True" : "False") << endl;

    string s2 = "rat";
    string t2 = "car";
    cout << (isAnagram(s2, t2) ? "True" : "False") << endl;
}

int main()
{
    testIsAnagram();

    getchar();
    return 0;
}