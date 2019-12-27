//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int longestPalindrome2(string s)
//{
//    if (s.empty())
//        return 0;
//
//    vector<int> count(128);
//    for (char c : s)
//    {
//        ++count[c];
//    }
//
//    int res = 0, flag = 0;
//    for (int i = 0; i < 128; ++i)
//    {
//        if ((count[i] & 1))
//        {
//            flag = 1;
//        }
//
//        res += count[i] / 2 * 2;
//    }
//    return flag == 1? res + 1: res;
//}
//
//int longestPalindrome(string s)
//{
//    int odds = 0;
//    for (char c = 'A'; c <= 'z'; ++c)
//        odds += count(s.begin(), s.end(), c) & 1;
//
//    return s.size() - odds + (odds > 0);
//}
//
//void testLongestPalindrome()
//{
//    string s1 = "abccccdd";
//    cout << longestPalindrome(s1) << endl;
//}
//
//int main()
//{
//    testLongestPalindrome();
//
//    getchar();
//    return 0;
//}