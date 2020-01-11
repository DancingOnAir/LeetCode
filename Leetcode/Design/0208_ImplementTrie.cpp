#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TriNode
{
    bool isEnd;
    vector<TriNode*> children;

    TriNode(bool x = false) : isEnd(x), children(26, nullptr) {};
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

            if (i == word.size() - 1)
                cur->isEnd = true;
        }

    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (word.empty())
            return true;

        auto head = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int pos = word[i] - 'a';
            if (head->children[pos] == nullptr)
                return false;

            head = head->children[pos];
        }

        return head->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (prefix.empty())
            return true;

        auto head = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int pos = prefix[i] - 'a';
            if (head->children[pos] == nullptr)
                return false;

            head = head->children[pos];
        }

        return true;
    }

private:
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