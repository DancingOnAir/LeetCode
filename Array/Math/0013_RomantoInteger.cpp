//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int romanToInt(string s)
//{
//    int res = 0;
//    
//    if (s.find("IV") != s.npos)
//        res -= 2;
//    if (s.find("IX") != s.npos)
//        res -= 2;
//    if (s.find("XL") != s.npos)
//        res -= 20;
//    if (s.find("XC") != s.npos)
//        res -= 20;
//    if (s.find("CD") != s.npos)
//        res -= 200;
//    if (s.find("CM") != s.npos)
//        res -= 200;
//
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (s[i] == 'M')
//            res += 1000;
//        else if (s[i] == 'D')
//            res += 500;
//        else if (s[i] == 'C')
//            res += 100;
//        else if (s[i] == 'L')
//            res += 50;
//        else if (s[i] == 'X')
//            res += 10;
//        else if (s[i] == 'V')
//            res += 5;
//        else if (s[i] == 'I')
//            res += 1;
//        else
//            return 0;
//    }
//
//    return res;
//}
//
//void testRomanToInt()
//{
//    cout << romanToInt("III") << endl;
//    cout << romanToInt("IV") << endl;
//    cout << romanToInt("IX") << endl;
//    cout << romanToInt("LVIII") << endl;
//    cout << romanToInt("MCMXCIV") << endl;
//}
//
//int main()
//{
//    testRomanToInt();
//
//    getchar();
//    return 0;
//}