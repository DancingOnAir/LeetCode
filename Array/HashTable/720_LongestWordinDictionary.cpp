//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <map>
//#include <set>
//using namespace std;
//
//string longestWord2(vector<string>& words)
//{
//
//    if (words.empty())
//        return "";
//    
//    unordered_map<string, int> m;
//    for (string& word : words)
//        m[word] = word.size();
//
//    map<int, set<string>> n;
//    for (auto w : m)
//    {
//        n[w.second].emplace(w.first);
//    }
//
//    size_t len = n.size();
//    int k = n.begin()->first;
//    set<string> res = n.begin()->second;
//    ++k;
//
//    while (n.count(k))
//    {
//        set<string> s;
//        for (const string& tmp : n[k])
//        {
//            for (const string& r : res)
//            {
//                if (tmp.find(r) != string::npos)
//                {
//                    s.emplace(tmp);
//                    break;
//                }
//            }
//        }
//
//        if (s.empty())
//            break;
//
//        res.clear();
//        res.swap(s);
//        ++k;
//        
//    }
//
//    return *res.begin();
//}
//
//struct TrieNode
//{
//    bool isEnd;
//    vector<TrieNode*> next;
//
//    TrieNode(bool end = false) : isEnd(end), next(26, nullptr)
//    {
//
//    }
//};
//
//
//class Solution
//{
//public:
//    Solution()
//    {
//        root = new TrieNode();
//    }
//
//    ~Solution()
//    {
//        delete root;
//        root = nullptr;
//    }
//
//    void insert(string& word)
//    {
//        auto p = root;
//        for (char c : word)
//        {
//            int index = c - 'a';
//            if (p->next[index] == nullptr)
//                p->next[index] = new TrieNode();
//            p = p->next[index];
//        }
//
//        p->isEnd = true;
//    }
//
//    string search()
//    {
//        string res("");
//        int maxLen = INT_MIN;
//        helper(root, 0, "", maxLen, res);
//
//        return res;
//    }
//
//    void helper(TrieNode* node, int curr, string str, int& maxLen, string& res)
//    {
//        TrieNode* temp = node;
//        for (int i = 0; i < 26; ++i)
//        {
//            if (temp->next[i] == nullptr)
//                continue;
//
//            if (temp->next[i]->isEnd)
//            {
//                ++curr;
//                str += (char)(i + 'a');
//
//                res = curr > maxLen ? str : res;
//                maxLen = curr > maxLen ? curr : maxLen;
//
//                helper(temp->next[i], curr, str, maxLen, res);
//
//                --curr;
//                str.pop_back();
//            }
//        }
//    }
//
//    string longestWord(vector<string>& words)
//    {
//        for (string& word : words)
//            insert(word);
//
//        return search();
//    }
//
//private:
//    TrieNode* root;
//};
//
//void testLongestWord()
//{
//    //vector<string> words1 = { "w", "wo", "wor", "worl", "world" };
//    //cout << longestWord(words1) << endl;
//
//    vector<string> words2 = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
//    Solution solution;
//    cout << solution.longestWord(words2) << endl;
//}
//
//int main()
//{
//    testLongestWord();
//
//    getchar();
//    return 0;
//}