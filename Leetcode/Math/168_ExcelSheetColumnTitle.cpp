//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string convertToTitle(int n)
//{
//    if (n < 1)
//        return "";
//
//    string res("");
//    while (n > 0)
//    {
//        --n;
//        res = (char)((n % 26) + 'A') + res;
//
//        n = n / 26;
//    }
//
//    return res;
//}
//
//void testConvertToTitle()
//{
//    cout << convertToTitle(1) << endl;
//    cout << convertToTitle(26) << endl;
//    cout << convertToTitle(28) << endl;
//    cout << convertToTitle(701) << endl;
//}
//
//int main()
//{
//    testConvertToTitle();
//
//    getchar();
//    return 0;
//}