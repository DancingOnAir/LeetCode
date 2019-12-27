//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_set>
//#include <queue>
//using namespace std;
//
//void helper(string beginWord, string endWord, vector<string>& wordList, vector<vector<string>>& res, vector<string>& path, string& curWord)
//{
//
//    if (curWord == endWord)
//    {
//        res.emplace_back(path);
//        //path.clear();
//
//        return;
//    }
//
//    if (curWord == beginWord)
//    {
//        path.emplace_back(curWord);
//    }
//    //else
//    //{
//    //    if (find(wordList.begin(), wordList.end(), curWord) == wordList.end())
//    //        return;
//
//    //    path.emplace_back(curWord);
//    //}
//
//    for (auto iter = curWord.begin(); iter != curWord.end(); ++iter)
//    {
//        char temp = *iter;
//        for (char c = 'a'; c <= 'z'; ++c)
//        {
//            *iter = c;
//            auto it = find(wordList.begin(), wordList.end(), curWord);
//            
//            if (it != wordList.end())
//            {
//                path.emplace_back(curWord);
//                string s = *it;
//                *it = "";
//
//                helper(beginWord, endWord, wordList, res, path, curWord);
//
//                *it = s;
//                path.pop_back();
//            }
//
//        }
//
//        *iter = temp;
//    }
//}
//
//vector<string> getNextWords(unordered_set<string>& wordList, string target)
//{
//    vector<string> res;
//    for (auto iter = target.begin(); iter != target.end(); ++iter)
//    {
//        char temp = *iter;
//
//        for (char c = 'a'; c <= 'z'; ++c)
//        {
//            *iter = c;
//            if (wordList.find(target) != wordList.end())
//                res.emplace_back(target);
//        }
//
//        *iter = temp;
//    }
//
//    return res;
//}
//
//vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
//{
//    vector<vector<string>> res;
//    unordered_set<string> s(wordList.begin(), wordList.end());
//    if (s.find(endWord) == s.end())
//        return res;
//
//    unordered_set<string> visited;
//    queue<vector<string>> q;
//    q.push({ beginWord });
//    bool isShortestPath = false;
//
//    while (!q.empty())
//    {
//        int len = q.size();
//        for (int i = 0; i < len; ++i)
//        {
//            vector<string> cur = q.front();
//            q.pop();
//
//            vector<string> nextWords = getNextWords(s, cur.back());
//            for (int j = 0; j < nextWords.size(); ++j)
//            {
//                vector<string> newPath(cur.begin(), cur.end());
//                newPath.emplace_back(nextWords[j]);
//
//                if (nextWords[j] == endWord)
//                {
//                    isShortestPath = true;
//                    res.emplace_back(newPath);
//                }
//
//                visited.insert(nextWords[j]);
//                q.emplace(newPath);
//            }
//        }
//
//        if (isShortestPath)
//            break;
//
//        for (auto iter = visited.begin(); iter != visited.end(); ++iter)
//            s.erase(*iter);
//
//        visited.clear();
//    }
//
//    return res;
//}
//
//void testFindLadders()
//{
//    string beginWord = "hit";
//    string endWord = "cog";
//    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
//    auto res = findLadders(beginWord, endWord, wordList);
//
//    for (auto& row : res)
//    {
//        for (auto& col : row)
//            cout << col << ", ";
//        cout << endl;
//    }
//}
//
//int main()
//{
//    testFindLadders();
//    getchar();
//}