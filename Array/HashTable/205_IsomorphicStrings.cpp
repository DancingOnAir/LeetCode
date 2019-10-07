#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isIsomorphic2(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<int, vector<int>> ms, mt;
    unordered_map<char, int> ns, nt;
    vector<int> aplha;

    for (int i = 0; i < s.size(); ++i)
    {
        if (!ns.count(s[i]))
            ns[s[i]] = i;

        if (!nt.count(t[i]))
            nt[t[i]] = i;
        
        ms[ns[s[i]]].emplace_back(i);
        mt[nt[t[i]]].emplace_back(i);
    }

    return ms == mt;
}

bool isIsomorphic(string s, string t)
{
    vector<int> ms(256, -1);
    vector<int> mt(256, -1);

    for (int i = 0; i < s.size(); ++i)
    {
        if (ms[s[i]] != mt[t[i]])
            return false;

        ms[s[i]] = mt[t[i]] = i;
    }

    return true;
}


void testIsIsomorphic()
{
    string s1 = "egg";
    string t1 = "add";
    cout << (isIsomorphic(s1, t1) ? "True" : "False") << endl;

    string s2 = "foo";
    string t2 = "bar";
    cout << (isIsomorphic(s2, t2) ? "True" : "False") << endl;

    string s3 = "paper";
    string t3 = "title";
    cout << (isIsomorphic(s3, t3) ? "True" : "False") << endl;
}

int main()
{
    testIsIsomorphic();

    getchar();
    return 0;
}