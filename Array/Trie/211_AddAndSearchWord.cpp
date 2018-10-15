//#include <iostream>
//#include <string>
//
//using namespace std;
//struct TrieNode
//{
//    bool isEnd;
//    TrieNode *next[26] = { nullptr };
//    TrieNode() : isEnd(false) {}
//};
//
//class WordDictionary {
//public:
//    /** Initialize your data structure here. */
//    WordDictionary(): root(new TrieNode())
//    {
//
//    }
//
//    /** Adds a word into the data structure. */
//    void addWord(const string& word) 
//    {
//        auto p = root;
//        
//        for (auto c : word)
//        {
//            int index = c - 'a';
//            if (nullptr == p->next[index])
//                p->next[index] = new TrieNode();
//            p = p->next[index];
//        }
//
//        p->isEnd = true;
//    }
//
//    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
//    bool search(string word) 
//    {
//        return retrieve(word, root);
//    }
//
//private:
//    bool retrieve(string& word, TrieNode *node)
//    {
//        auto p = node;
//
//        for (int i = 0; i < word.size(); ++i)
//        {
//            if (p && word[i] != '.')
//            {
//                int index = word[i] - 'a';
//                p = p->next[index];
//            }
//            else if (p && '.' == word[i])
//            {
//                TrieNode *temp = p;
//                for (int j = 0; j < 26; ++j)
//                {
//                    p = temp->next[j];
//                    if (retrieve(word.substr(i + 1), p))
//                        return true;
//                }
//            }
//            else
//            {
//                break;
//            }
//
//        }
//
//        return p && p->isEnd;
//    }
//
//    TrieNode *root;
//};
//
//int main()
//{
//    WordDictionary obj = WordDictionary();
//    obj.addWord("bad");
//    obj.addWord("dad");
//    obj.addWord("mad");
//    bool param_1 = obj.search("pad");
//    bool param_2 = obj.search("bad");
//    bool param_3 = obj.search(".ad");
//    bool param_4 = obj.search("b..");
//
//    std::cout << param_1 << ", " << param_2 << ", " << param_3 << ", " << param_4 << std::endl;
//
//    system("pause");
//    return 0;
//}