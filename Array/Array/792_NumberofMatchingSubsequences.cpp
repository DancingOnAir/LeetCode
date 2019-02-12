#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSubseq(string S, string& word)
{
    for (int i = 0; i < word.size(); ++i)
    {
        auto pos = S.find_first_of(word[i]);
        if (pos == string::npos)
            return false;

        S = S.substr(pos + 1, S.size() - pos - 1);
    }

    return true;
}

int numMatchingSubseq(string S, vector<string>& words)
{
    int res = 0;
    for (int i = 0; i < words.size(); ++i)
    {
        if (isSubseq(S, words[i]))
            ++res;
    }

    return res;
}

int numMatchingSubseq2(string S, vector<string>& words)
{
    vector<vector<int>> records(26);
    for (int i = 0; i < S.size(); ++i)
    {
        records[S[i] - 'a'].emplace_back(i);
    }

    int res = 0;
    for (const string& word : words)
    {
        int x = -1;
        bool found = true;
        for (char c : word)
        {
            auto iter = upper_bound(records[c - 'a'].begin(), records[c - 'a'].end(), x);
            if (iter == records[c - 'a'].end())
            {
                found = false;
                break;
            }
            else
                x = *iter;
        }

        if (found)
            ++res;
    }

    return res;
}

int numMatchingSubseq3(string S, vector<string>& words) {
    vector<const char*> waiting[128];

    for (auto &w : words)
        waiting[w[0]].push_back(w.c_str());

    for (char c : S) {
        auto advance = waiting[c];
        waiting[c].clear();

        for (auto it : advance)
            waiting[*++it].push_back(it);
    }
    return waiting[0].size();
}

void testNumMatchingSubseq()
{
    string S = "abcde";
    vector<string> words = { "a", "bb", "acd", "ace" };

    cout << numMatchingSubseq3(S, words) << endl;
}

int main()
{
    testNumMatchingSubseq();

    getchar();
    return 0;
}