//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//#include <string>
//
//using namespace std;
//
//vector<string> findWords2(vector<string>& words)
//{
//    if (words.empty())
//        return vector<string>();
//
//    unordered_map<int, unordered_set<char>> count{ {1, {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'}}, 
//                                                {2, {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' }}, 
//                                                {3, {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}} };
//    vector<string> res;
//    int flag = 0;
//    for (auto& word : words)
//    {
//        for (auto& iter : count)
//        {
//            if (iter.second.count(toupper(word[0])))
//                flag = iter.first;
//        }
//
//        int i = 1;
//        for (; i < word.size(); ++i)
//        {
//            char tmp = toupper(word[i]);
//            if (!count[flag].count(tmp))
//                break;
//        }
//
//        if (i == word.size())
//            res.emplace_back(word);
//        flag = 0;
//    }
//
//    return res;
//}
//
//vector<string> findWords(vector<string>& words)
//{
//    if (words.empty())
//        return vector<string>();
//
//    vector<int> dict(26);
//    vector<string> rows = { "QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM" };
//    for (int i = 0; i < rows.size(); ++i)
//    {
//        for (char c : rows[i])
//            dict[toupper(c) - 'A'] = 1 << i;
//    }
//
//    vector<string> res;
//    for (auto& w : words)
//    {
//        int r = 7;
//        for (char c : w)
//        {
//            r &= dict[toupper(c) - 'A'];
//            if (!r)
//                break;
//        }
//
//        if (r)
//            res.emplace_back(w);
//    }
//
//    return res;
//}
//
//void display(const vector<string>& words)
//{
//    for (auto& word : words)
//        cout << word << ", ";
//    cout << endl;
//}
//
//void testFindWords()
//{
//    vector<string> words{ "Hello", "Alaska", "Dad", "Peace" };
//    auto res = findWords(words);
//    display(res);
//}
//
//int main()
//{
//    testFindWords();
//
//    getchar();
//    return 0;
//}