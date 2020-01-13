#pragma once
#include <string>
#include <vector>
using namespace std;

struct TriNode
{
    bool isEnd;
    vector<TriNode*> children;

    TriNode(): isEnd(false), children(26, nullptr)
    {
    }
};

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root_ = new TriNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        auto cur = root_;
        for (char c : word)
        {
            int pos = c - 'a';
            if (cur->children[pos] == nullptr)
            {
                cur->children[pos] = new TriNode();
            }

            cur = cur->children[pos];
        }

        cur->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return retrieve(word, root_);
    }

    TriNode* getRoot()
    {
        return root_;
    }

private:
    bool retrieve(const string& word, TriNode* root)
    {
        for (int i = 0; word[i] && root; ++i)
        {
            if (word[i] == '.')
            {
                auto p = root;
                for (int j = 0; j < 26; ++j)
                {
                    root = p->children[j];
                    if (retrieve(word.substr(i + 1), root))
                        return true;
                }
            }
            else
            {
                root = root->children[word[i] - 'a'];
            }
        }

        return root && root->isEnd;
    }

    TriNode* root_;
};