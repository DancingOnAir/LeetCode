#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

char findTheDifference(string s, string t)
{
    if (s.empty())
        return t[0];

    vector<int> vs(26);
    vector<int> vt(26);

    for (int i = 0; i < t.size(); ++i)
    {
        if (i < s.size())
            ++vs[s[i] - 'a'];
        ++vt[t[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i)
    {
        if (vt[i] != vs[i])
            return 'a' + i;
    }

    return t[0];
}

void testFindTheDifference()
{
    string s1 = "abcd";
    string t1 = "abcde";
    cout << findTheDifference(s1, t1) << endl;
}

int main()
{
    testFindTheDifference();

    getchar();
    return 0;
}