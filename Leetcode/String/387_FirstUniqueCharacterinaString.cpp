//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int firstUniqChar(string s)
//{
//    if (s.empty())
//        return -1;
//
//    vector<vector<int>> dict(26, vector<int>());
//    for (int i = 0; i < s.size(); ++i)
//    {
//        dict[s[i] - 'a'].emplace_back(i);
//    }
//
//    int res = INT_MAX;
//    for (int i = 0; i < dict.size(); ++i)
//    {
//        if (dict[i].size() == 1)
//            res = res > dict[i][0] ? dict[i][0] : res;
//    }
//
//    return res == INT_MAX ? -1 : res;
//}
//
//void testFirstUniqChar()
//{
//    string s1 = "leetcode";
//    cout << firstUniqChar(s1) << endl;
//
//    string s2 = "loveleetcode";
//    cout << firstUniqChar(s2) << endl;
//}
//
//int main()
//{
//    testFirstUniqChar();
//
//    getchar();
//    return 0;
//}