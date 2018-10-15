#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode
{
    bool isEnd;
    TrieNode *children[26] = { nullptr };
    TrieNode() : isEnd(false) {}
};

class Trie
{
public:
    Trie() : root(new TrieNode())
    {

    }

    Trie(vector<string>& words)
    {
        root = new TrieNode();
        for (auto s : words)
            insert(s);
    }

    void insert(const string& word)
    {
        auto p = root;
        for (auto c : word)
        {
            int index = c - 'a';
            if (nullptr == p->children[index])
                p->children[index] = new TrieNode();
            p = p->children[index];
        }

        p->isEnd = true;
    }

    TrieNode* getChild(TrieNode* p, const char c)
    {
        int index = c - 'a';
        if (nullptr == p->children[index])
            return nullptr;

        return p->children[index];
    }

    TrieNode* getRoot()
    {
        return root;
    }

private:
    TrieNode* retrieve(const string& word)
    {
        auto p = root;
        for (auto c : word)
        {
            int index = c - 'a';
            if (nullptr == p->children[index])
                break;

            p = p->children[index];
        }

        return p;
    }

    TrieNode *root;
};

void check(vector<vector<char>>& board, vector<string>& result, string s, TrieNode *root, int col, int row)
{
    if (col < 0 || col >= board.size() || row < 0 || row >= board[0].size() || ' ' == board[col][row])
        return;

    int index = board[col][row] - 'a';
    if (root->children[index] != nullptr)
    {
        s += board[col][row];
        root = root->children[index];

        if (true == root->isEnd && find(result.begin(), result.end(), s) == result.end())
            result.emplace_back(s);

        char c = board[col][row];
        board[col][row] = ' ';
        check(board, result, s, root, col - 1, row);
        check(board, result, s, root, col + 1, row);
        check(board, result, s, root, col, row - 1);
        check(board, result, s, root, col, row + 1);
        board[col][row] = c;
    }
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
    vector<string> result;
    if (words.empty())
        return result;

    Trie *t = new Trie(words);
    auto root = t->getRoot();

    for (size_t i = 0; i < board.size(); ++i)
    {
        for (size_t j = 0; j < board[0].size(); ++j)
        {
            check(board, result, "", root, i, j);
        }
    }

    return result;
}

int main()
{
    //vector<string> words = { "oath", "pea", "eat", "rain" };
    //vector<vector<char>> board =
    //{
    //    {'o', 'a', 'a', 'n'},
    //    {'e', 't', 'a', 'e'},
    //    {'i', 'h', 'k', 'r'},
    //    {'i', 'f', 'l', 'v'}
    //};
    vector<string> words = { "aaa" };
    vector<vector<char>> board = { {'a', 'a'} };

    auto result = findWords(board, words);
    for (auto s : result)
        cout << s << ", ";
    cout << endl;

    system("pause");
    return 0;
}