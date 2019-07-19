//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//bool checkPerfectNumber(int num)
//{
//    if (num < 2)
//        return false;
//
//    int rest = num;
//    for (int i = 2; i * i <= num; ++i)
//    {
//        if (num % i == 0)
//            rest -= (i + num / i);
//    }
//
//    return 1 == rest;
//}
//
////欧拉曾推算出完全数的获得公式：如果p是质数，且2^p - 1也是质数，那么（2^p - 1）X2^（p - 1）便是一个完全数
//bool checkPerfectNumber2(int num)
//{
//    int p[] = { 2, 3, 5, 7, 13 };
//    for (int& i : p)
//        i = ((1 << i) - 1) * (1 << (i - 1));
//
//    return binary_search(begin(p), end(p), num);
//}
//
//void testCheckPerfectNumber()
//{
//    cout << (checkPerfectNumber2(6) ? "T" : "F") << endl;
//    cout << (checkPerfectNumber2(28) ? "T" : "F") << endl;
//    cout << (checkPerfectNumber2(30) ? "T" : "F") << endl;
//    cout << (checkPerfectNumber2(100000000) ? "T" : "F") << endl;
//}
//
//int main()
//{
//    testCheckPerfectNumber();
//    getchar();
//    return 0;
//}