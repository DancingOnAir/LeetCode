#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

vector<int> findAnagrams(string s, string p) 
{
    vector<int> vs(256, 0), vp(256, 0), result;

    if (s.size() < p.size())
        return result;

    for (int i = 0; i < p.size(); ++i)
    {
        ++vs[s[i]];
        ++vp[p[i]];
    }

    if (vp == vs)
        result.push_back(0);

    for (int i = p.size(); i < s.size(); ++i)
    {
        ++vs[s[i]];
        --vs[s[i - p.size()]];

        if (vp == vs)
            result.push_back(i - p.size() + 1);
    }

    return result;
}

int main()
{

//s: "cbaebabacd" p : "abc"
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);

    for (auto v : result)
        cout << v << " ";
    cout << endl;

    return 0;
}