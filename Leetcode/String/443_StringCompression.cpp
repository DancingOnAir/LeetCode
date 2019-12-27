//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int compress2(vector<char>& chars)
//{
//    int count = 0;
//    vector<char> res;
//    int n = chars.size();
//    if (1 == n)
//        return 1;
//
//    for (int i = 0; i < n; ++i)
//    {
//        int num = 0;
//        int j = i;
//        while (j < n - 1 && chars[j] == chars[j + 1])
//        {
//            ++j;
//        }
//
//        res.emplace_back(chars[i]);
//
//        if (j != i)
//        {
//            num = j + 1 - i;
//            i = j;
//
//            for (char c : to_string(num))
//                res.emplace_back(c);
//        }
//    }
//
//    chars.assign(res.begin(), res.end());
//    return res.size();
//}
//
//int compress(vector<char>& chars)
//{
//    int i = 0, t = 0;
//    for (int j = 0; j < chars.size(); ++j)
//    {
//        if (j + 1 == chars.size() || chars[j] != chars[j + 1])
//        {
//            int m = t;
//            chars[t++] = chars[j];
//            if (j >= i + 1)
//            {
//                string s = to_string(j - i + 1);
//                for (char c : s)
//                    chars[t++] = c;
//            }
//
//            i = j + 1;
//
//        }
//    }
//
//    return chars.size();
//}
//
//void testCompress()
//{
//    vector<char> chars4{ 'a','b','c' };
//    cout << compress(chars4) << endl;
//
//    vector<char> chars1{ 'a','a','b','b','c','c','c' };
//    cout << compress(chars1) << endl;
//
//    vector<char> chars2{ 'a' };
//    cout << compress(chars2) << endl;
//
//    vector<char> chars3{ 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
//    cout << compress(chars3) << endl;
//}
//
//int main()
//{
//    testCompress();
//
//    getchar();
//    return 0;
//}