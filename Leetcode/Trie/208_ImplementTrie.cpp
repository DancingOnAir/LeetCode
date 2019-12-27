//#include <iostream>
//#include <vector>
//#include <string>
//
//struct TrieNode
//{
//    bool isEnd;
//    TrieNode *children[26] = { nullptr};
//    TrieNode() : isEnd(false) {};
//};
//
//class Trie
//{
//public:
//    Trie(): root(new TrieNode())
//    {
//
//    }
//
//    //void destroy(TrieNode *node)
//    //{
//    //    for (int i = 0; i < 26; ++i)
//    //    {
//    //        if (node->children[i] != nullptr)
//    //            destroy(node->children[i]);
//    //    }
//
//    //    delete node;
//    //}
//
//    //~Trie()
//    //{
//    //    destroy(root);
//    //}
//
//    void insert(const std::string& word)
//    {
//        auto p = root;
//
//        for (auto c : word)
//        {
//            int index = c - 'a';
//            if (p->children[index] == nullptr)
//                p->children[index] = new TrieNode();
//
//            p = p->children[index];
//        }
//
//        p->isEnd = true;
//    }
//
//    bool search(const std::string& word)
//    {
//        auto node = retrieve(word);
//        return node && node->isEnd;
//    }
//
//    bool startsWith(const std::string& prefix)
//    {
//        return retrieve(prefix);
//    }
//
//private:
//    TrieNode* retrieve(const std::string& prefix)
//    {
//        auto p = root;
//        for (auto c : prefix)
//        {
//            int index = c - 'a';
//            p = p->children[index];
//            if (!p)
//                break;
//        }
//
//        return p;
//    }
//
//    TrieNode *root;
//};
//
//int main()
//{
//    Trie obj = Trie();
//    obj.insert("apple");
//    bool param_2 = obj.search("app");
//    bool param_3 = obj.startsWith("app");
//
//    std::cout << param_2 << ", " << param_3 << std::endl;
//
//    system("pause");
//    return 0;
//}