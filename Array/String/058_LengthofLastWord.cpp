//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int lengthOfLastWord(string s)
//{
//    if (s.empty())
//        return 0;
//
//    int res = 0;
//    int pos = s.find_last_not_of(' ');
//    string s1 = s.substr(0, pos + 1);
//    pos = s1.find_last_of(' ');
//    return s1.size() - pos - 1;
//}
//
//void testLengthOfLastWord()
//{
//    string s1 = "Hello World";
//    cout << lengthOfLastWord(s1) << endl;
//
//    string s2 = "a ";
//    cout << lengthOfLastWord(s2) << endl;
//}
//
//int main()
//{
//    testLengthOfLastWord();
//
//    getchar();
//    return 0;
//}
