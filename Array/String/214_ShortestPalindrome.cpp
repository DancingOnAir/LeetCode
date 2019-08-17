#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string shortestPalindrome2(string s)
{
    if (s.empty())
        return "";

    int n = s.size();
    int i = n - 1;

    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    for (int i = 0; i < s.size(); ++i)
    {
        if (revStr.substr(i) == s.substr(0, s.size() - i))
        {
            return revStr.substr(0, i) + s;
        }
    }

    return revStr + s;
}

string shortestPalindrome(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    string mirror = s + "#" + rs;
    vector<int> next(mirror.size());

    for (int i = 1; i < mirror.size(); ++i)
    {
        int j = next[i - 1];
        while (j > 0 && mirror[i] != mirror[j])
            j = next[j - 1];
        next[i] = (j += mirror[i] == mirror[j]);
    }

    int matchnums = next[mirror.size() - 1];
    int mismatch = s.size() - matchnums;
    return rs.substr(0, mismatch) + s;
}

void testShortestPalindrome()
{
    string input1 = "aacecaaa";
    cout << shortestPalindrome(input1) << endl;

    string input2 = "abcd";
    cout << shortestPalindrome(input2) << endl;

    string input3 = "abbacd";
    cout << shortestPalindrome(input3) << endl;
}

int main()
{
    testShortestPalindrome();

    getchar();
    return 0;
}