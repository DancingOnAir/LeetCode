#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int longestValidParentheses2(string s)
{
    int n = s.size();
    if (n < 2)
        return 0;

    stack<int> stk;
    stk.emplace(-1);
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        int temp = stk.top();
        if (temp != -1 && s[temp] == '(' && s[i] == ')')
        {
            stk.pop();
            res = res > (i - stk.top()) ? res : i - stk.top();
        }
        else
            stk.emplace(i);
    }

    return res;
}

int longestValidParentheses(string s)
{
    int n = s.size();
    if (n < 2)
        return 0;

    vector<int> dp(n);
    int res = 0;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
                dp[i] = (i > 2 ? dp[i - 2] : 0) + 2;
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 > 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;

            res = res > dp[i] ? res : dp[i];
        }
    }

    return res;
}

void testLongestValidParentheses()
{
    string s1 = "()(())";
    cout << longestValidParentheses(s1) << endl;

    string s2 = "(()())";
    cout << longestValidParentheses(s2) << endl;
}

int main()
{
    testLongestValidParentheses();

    getchar();
    return 0;
}