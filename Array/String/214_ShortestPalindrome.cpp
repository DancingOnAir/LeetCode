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

vector<int> getNext(string& p)
{
    vector<int> next(p.size());
    next[0] = -1;
    int i = -1;
    int j = 0;

    while (j < p.size() - 1)
    {
        if (i == -1 || p[i] == p[j])
        {
            ++i;
            ++j;


            next[j] = i;

        }
        else
        {
            i = next[i];
        }
    }

    return next;
}

string shortestPalindrome(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    string mirror = s + "#" + rs;
    
    auto next = getNext(mirror);

    int matchnums = next[mirror.size() - 1] + 1;
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