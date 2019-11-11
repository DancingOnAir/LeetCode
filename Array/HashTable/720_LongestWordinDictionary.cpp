#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

string longestWord(vector<string>& words)
{

    if (words.empty())
        return "";
    
    unordered_map<string, int> m;
    for (string& word : words)
        m[word] = word.size();

    map<int, set<string>> n;
    for (auto w : m)
    {
        n[w.second].emplace(w.first);
    }

    size_t len = n.size();
    int k = n.begin()->first;
    set<string> res = n.begin()->second;
    ++k;

    while (n.count(k))
    {
        set<string> s;
        for (const string& tmp : n[k])
        {
            for (const string& r : res)
            {
                if (tmp.find(r) != string::npos)
                {
                    s.emplace(tmp);
                    break;
                }
            }
        }

        if (s.empty())
            break;

        res.clear();
        res.swap(s);
        ++k;
        
    }

    return *res.begin();
}

void testLongestWord()
{
    //vector<string> words1 = { "w", "wo", "wor", "worl", "world" };
    //cout << longestWord(words1) << endl;

    vector<string> words2 = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    cout << longestWord(words2) << endl;
}

int main()
{
    testLongestWord();

    getchar();
    return 0;
}