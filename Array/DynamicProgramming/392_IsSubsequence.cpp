#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isSubsequence2(string s, string t)
{
    if (s.empty())
        return true;

    if (t.empty())
        return false;

    int l1 = s.size();
    int l2 = t.size();

    if (l1 > l2)
        return false;

    int start = 0;
    bool found = false;
    for (int i = 0; i < l1; ++i)
    {
        found = false;
        for (int j = start; j < l2; ++j)
        {
            if (s[i] == t[j])
            {
                start = j + 1;
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}

bool isSubsequence(string s, string t)
{
    if (s.empty())
        return true;

    if (t.empty())
        return false;

    int l1 = s.size();
    int l2 = t.size();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, false));
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (t[j - 1] == s[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }

        }
    }

    return dp[l1][l2] == l1;
}

void testIsSubsequence()
{
    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";
    string s3 = "b", t3 = "c";
    cout << (isSubsequence(s1, t1) ? "True" : "False") << endl;
    cout << (isSubsequence(s2, t2)? "True":"False") << endl;
    cout << (isSubsequence(s3, t3) ? "True" : "False") << endl;
}

int main()
{
    testIsSubsequence();

    getchar();
    return 0;
}