#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p)
{
    int m = s.size();
    int n = p.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    for (int j = 0; j <= n; ++j)
    {
        if (j == 0 || p[j - 1] == '*')
            dp[0][j] = true;
        else
            break;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    return dp[m][n];
}

void testIsMatch()
{
    string s1 = "aa";
    string p1 = "a";
    cout << (isMatch(s1, p1) ? "True" : "False") << endl;

    string s2 = "aa";
    string p2 = "*";
    cout << (isMatch(s2, p2) ? "True" : "False") << endl;

    string s3 = "cb";
    string p3 = "?a";
    cout << (isMatch(s3, p3) ? "True" : "False") << endl;

    string s4 = "adceb";
    string p4 = "a*b";
    cout << (isMatch(s4, p4) ? "True" : "False") << endl;

    string s5 = "acdcb";
    string p5 = "a*c?b";
    cout << (isMatch(s5, p5) ? "True" : "False") << endl;
}

int main()
{
    testIsMatch();

    getchar();
    return 0;
}
