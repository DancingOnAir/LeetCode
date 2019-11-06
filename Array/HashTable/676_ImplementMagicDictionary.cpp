#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for (auto& d : dict)
        {
            m[d.size()].emplace_back(d);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        int n = word.size();
        if (m.count(n))
        {
            for (string& str : m[n])
            {
                int flag = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (word[i] != str[i])
                    {
                        ++flag;
                        if (flag > 1)
                            break;
                    }
                }

                if (flag == 1)
                    return true;
            }
        }

        return false;
    }

private:
    unordered_map<int, vector<string>> m;
};

void testMagicDictionary()
{
    MagicDictionary* obj = new MagicDictionary();
    vector<string> dict = { "hello", "leetcode" };
    obj->buildDict(dict);
    cout << (obj->search("hello") ? "True" : "False") << endl;
    cout << (obj->search("hhllo") ? "True" : "False") << endl;
    cout << (obj->search("hell") ? "True" : "False") << endl;
    cout << (obj->search("leetcoded") ? "True" : "False") << endl;
}

int main()
{
    testMagicDictionary();

    getchar();
    return 0;
}