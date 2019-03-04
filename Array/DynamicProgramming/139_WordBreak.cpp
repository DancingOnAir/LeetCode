#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    if (s.empty() || wordDict.empty())
        return false;

    set<string> dict;
    for (string& word : wordDict)
    {
        dict.insert(word);
    }

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (dp[j])
            {
                if (dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }


    return dp[s.size()];
}

void testWordBreak()
{
    string s = "applepenapple";
    vector<string> wordDict = { "apple", "pen" };

    string s1 = "catsandog";
    vector<string> wordDict1 = { "cats", "dog", "sand", "and", "cat" };

    cout << (wordBreak(s1, wordDict1) ? "true" : "false") << endl;
}

int main()
{
    testWordBreak();

    getchar();
    return 0;
}