#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p)
{
    int lenOfP = p.size();
    int lenOfS = s.size();
    int i = 0, j = 0, iAsterisk = -1, jAsterisk = -1;

    for (i = 0, j = 0; i < lenOfS; ++i, ++j)
    {
        if (s[j] == '*')
        {
            iAsterisk = i;
            jAsterisk = j;
            --i;
        }
        else
        {
            if (p[i] != s[j] || s[j] != '?')
            {
                if (iAsterisk >= 0)
                {
                    i = iAsterisk++;
                    j = jAsterisk;
                }
                else
                    return false;
            }
        }
    }

    while (p[j] == '*')
        ++j;

    return j == lenOfP;
}

bool isMatch2(string s, string p)
{
    int slen = s.size();
    int plen = p.size();

    if (plen > 3000)
        return false;

    vector<bool> dp(slen + 1, false);
    dp[0] = true;
    for (int j = 1; j <= plen; ++j)
    {
        bool pre = dp[0];
        dp[0] = dp[0] && p[j - 1] == '*';

        for (int i = 1; i <= slen; ++i)
        {
            bool temp = dp[i];
            if (p[j - 1] != '*')
                dp[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
            else
                dp[i] = dp[i] || dp[i - 1];

            pre = temp;
        }
    }

    return dp[slen];
}

void testIsMatch()
{
    string s = "acdcb";
    string p = "a*c?b";

    cout << (isMatch(s, p) ? "true" : "false") << endl;
}

int main()
{
    testIsMatch();

    getchar();
    return 0;
}