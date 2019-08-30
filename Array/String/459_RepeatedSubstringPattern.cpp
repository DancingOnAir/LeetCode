#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool repeatedSubstringPattern2(string s)
{
    if (s.empty())
        return false;

    int n = s.size();
    for (int i = 1; i < n; ++i)
    {
        if (n % i == 0)
        {
            int times = n / i;
            string temp("");
            while (times--)
            {
                temp += s.substr(0, i);
            }

            if (temp == s)
                return true;
        }
    }

    return false;
}

bool repeatedSubstringPattern3(string s)
{
    return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
}

bool repeatedSubstringPattern(string s)
{
    // i ºó×º£¬j Ç°×º
    int i = 1, j = 0, n = s.size();
    vector<int> dp(n + 1);
    
    while (i < n)
    {
        if (s[i] == s[j])
            dp[++i] = ++j;
        else if (j == 0)
            ++i;
        else
            j = dp[j];
    }

    return dp[n] && dp[n] % (n - dp[n]) == 0;
}

void testRepeatedSubstringPattern()
{
    string s4 = "bb";
    cout << (repeatedSubstringPattern(s4) ? "True" : "False") << endl;

    string s1 = "abab";
    cout << (repeatedSubstringPattern(s1) ? "True" : "False") << endl;

    string s2 = "aba";
    cout << (repeatedSubstringPattern(s2) ? "True" : "False") << endl;

    string s3 = "abcabcabcabc";
    cout << (repeatedSubstringPattern(s3) ? "True" : "False") << endl;
}

int main()
{
    testRepeatedSubstringPattern();

    getchar();
    return 0;
}