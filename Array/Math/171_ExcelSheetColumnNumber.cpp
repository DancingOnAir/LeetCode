//#include <iostream>
//#include <string>
//#include <math.h>
//using namespace std;
//
//int titleToNumber(string s) 
//{
//    if (s.empty())
//        return 0;
//
//    int res = 0;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        int v = s[i] - 'A' + 1;
//        res += v * pow(26, s.size() - i - 1);
//    }
//
//    return res;
//}
//
//void testTitleToNumber()
//{
//    cout << titleToNumber("A") << endl;
//    cout << titleToNumber("Z") << endl;
//    cout << titleToNumber("AB") << endl;
//    cout << titleToNumber("ZY") << endl;
//}
//
//int main()
//{
//    testTitleToNumber();
//
//    getchar();
//    return 0;
//}