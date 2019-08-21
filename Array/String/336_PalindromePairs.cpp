//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//
//bool isPalindrome(string word)
//{
//    int i = 0, j = word.size() - 1;
//    for (; i < j; ++i, --j)
//    {
//        if (word[i] != word[j])
//            return false;
//    }
//
//    return true;
//}
//
//vector<vector<int>> palindromePairs(vector<string>& words)
//{
//    vector<vector<int>> res;
//    unordered_map<string, int> dict;
//    if (words.empty())
//        return res;
//
//    for (int i = 0; i < words.size(); ++i)
//    {
//        dict[words[i]] = i;
//    }
//
//    for (int i = 0; i < words.size(); ++i)
//    {
//        for (int j = 0; j <= words[i].size(); ++j)
//        {
//            if (isPalindrome(words[i].substr(j)))
//            {
//                string suffix = words[i].substr(0, j);
//                reverse(suffix.begin(), suffix.end());
//                if (dict.find(suffix) != dict.end() && dict[suffix] != i)
//                {
//                    res.push_back({ i, dict[suffix] });
//                }
//            }
//
//            if (j > 0 && isPalindrome(words[i].substr(0, j)))
//            {
//                string prefix = words[i].substr(j);
//                reverse(prefix.begin(), prefix.end());
//                if (dict.find(prefix) != dict.end() && dict[prefix] != i)
//                {
//                    res.push_back({ dict[prefix], i });
//                }
//            }
//        }
//    }
//
//    return res;
//}
//
//void display(vector<vector<int>> p)
//{
//    for (auto& r : p)
//    {
//        for (auto& c : r)
//            cout << c << ", ";
//        cout << endl;
//    }
//}
//
//void testPalindromePairs()
//{
//    vector<string> words1{ "abcd","dcba","lls","s","sssll" };
//    auto res1 = palindromePairs(words1);
//    display(res1);
//
//    vector<string> words2{ "bat","tab","cat" };
//    auto res2 = palindromePairs(words2);
//    display(res2);
//}
//
//int main()
//{
//
//    testPalindromePairs();
//
//    getchar();
//    return 0;
//}