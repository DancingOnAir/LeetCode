//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;
//
//string minWindow(string s, string t)
//{
//    vector<int> v(128, 0);
//    for (char c : t)
//        v[c]++;
//
//    int counter = t.size();
//    int begin = 0, end = 0, minDist = INT_MAX, head = 0;
//    while (end < s.size())
//    {
//        if (v[s[end++]]-- > 0)
//            --counter;
//
//        while (0 == counter)
//        {
//            if (end - begin < minDist)
//                minDist = end - (head = begin);
//
//            if (v[s[begin++]]++ == 0)
//                ++counter;
//        }
//    }
//
//    return minDist == INT_MAX ? "" : s.substr(head, minDist);
//}
//
//void testMinWindow()
//{
//    string s = "ADOBECODEBANC", t = "ABC";
//    cout << minWindow(s, t) << endl;
//}
//
//int main()
//{
//    testMinWindow();
//
//    getchar();
//    return 0;
//}