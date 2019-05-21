#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    if (n < 2)
        return n;

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; --i)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; ++j)
        {
            if (s[j] == s[i])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][n - 1];
}

void testLongestPalindromeSubseq()
{
    string s1 = "bbbab";
    cout << longestPalindromeSubseq(s1) << endl;

    string s2 = "cbbd";
    cout << longestPalindromeSubseq(s2) << endl;
}


int main()
{
    testLongestPalindromeSubseq();
    getchar();
    return 0;
}