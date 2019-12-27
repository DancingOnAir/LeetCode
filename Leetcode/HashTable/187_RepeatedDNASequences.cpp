//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//vector<string> findRepeatedDnaSequences2(string s)
//{
//    if (s.size() < 11)
//        return vector<string>();
//
//    vector<string> res;
//    unordered_map<string, int> m;
//    for (int i = 0; i <= s.size() - 10; i++)
//    {
//        if (m[s.substr(i, 10)]++ == 1)
//            res.emplace_back(s.substr(i, 10));
//    }
//
//    return res;
//}
//
//vector<string> findRepeatedDnaSequences(string s)
//{
//    vector<string> res;
//    unordered_map<int, int> count;
//    for (int i = 0, h = 0; i < s.size(); ++i)
//    {
//        h = ((h & 0x07ffffff) << 3) | (s[i] & 7);
//        if ((count[h]++) == 1)
//            res.emplace_back(s.substr(i - 9, 10));
//    }
//
//    return res;
//}
//
//void display(vector<string>& v)
//{
//    for (string& s : v)
//        cout << s << ", ";
//    cout << endl;
//}
//
//void testFindRepeatedDnaSequences()
//{
//    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
//    auto res1 = findRepeatedDnaSequences(s1);
//    display(res1);
//
//    string s2 = "AAAAAAAAAAAA";
//    auto res2 = findRepeatedDnaSequences(s2);
//    display(res2);
//}
//
//int main()
//{
//    testFindRepeatedDnaSequences();
//
//    getchar();
//    return 0;
//}