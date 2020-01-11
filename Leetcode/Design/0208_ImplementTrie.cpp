#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TriNode
{
    bool isEnd;
    vector<TriNode*> children;

    TriNode() : isEnd(false), children(26, nullptr) {};
};

class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TriNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int pos = word[i] - 'a';
            if (cur->children[pos] == nullptr)
            {
                cur->children[pos] = new TriNode();
            }

            cur = cur->children[pos];
        }

        cur->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto p = retrieve(word);

        return p && p->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return retrieve(prefix);
    }

private:
    TriNode* retrieve(const string& prefix)
    {
        auto cur = root;
        for (char c : prefix)
        {
            int pos = c - 'a';
            cur = cur->children[pos];

            if (!cur)
                break;
        }

        return cur;
    }

    TriNode* root;
};

void test()
{
    Trie trie = Trie();

    trie.insert("apple");
    cout << (trie.search("apple")? "True" : "False") << endl;   // returns true
    cout << (trie.search("app")? "True" : "False") << endl;     // returns false
    cout << (trie.startsWith("app")? "True" : "False") << endl; // returns true
    trie.insert("app");
    cout << (trie.search("app")? "True" : "False") << endl;     // returns true
}

int main()
{
    test();

    getchar();
    return 0;
}