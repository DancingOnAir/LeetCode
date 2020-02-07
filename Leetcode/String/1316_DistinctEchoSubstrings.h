#pragma once
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution
{
public:
    //Rabin-Karp Algorithm
    int generateHash(vector<int>& pre, vector<int>& mul, int i, int j)
    {
        return (pre[j + 1] - (long long)pre[i] * mul[j - i + 1] % mod + mod) % mod;
    }

    int distinctEchoSubstrings(string text)
    {
        int n = text.size();
        if (n < 2)
            return 0;

        int base = 29;
        vector<int> pre(n + 1);
        vector<int> mul(n + 1);
        mul[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            pre[i + 1] = ((long long)pre[i] * base + text[i]) % mod;
            mul[i + 1] = ((long long)mul[i] * base) % mod;
        }

        unordered_set<string> s;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int len = 1; i + len + len <= n; ++len)
            {
                if (generateHash(pre, mul, i, i + len - 1) == generateHash(pre, mul, i + len, i + len + len - 1))
                {
                    s.emplace(text.substr(i, len));
                }
            }
        }

        return s.size();
    }

private:
    constexpr static long long mod = 1e9 + 7;
};