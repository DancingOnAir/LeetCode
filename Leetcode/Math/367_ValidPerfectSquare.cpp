//#include <iostream>
//
//using namespace std;
//
//bool isPerfectSquare(int num)
//{
//    if (num < 1)
//        return false;
//
//    long x = num;
//    while (x * x > num)
//    {
//        x = (x + num / x) / 2;
//    }
//
//    return x * x == num;
//}
//
//bool isPerfectSquare2(int num)
//{
//    int i = 1;
//    while (num > 0)
//    {
//        num -= i;
//        i += 2;
//    }
//
//    return 0 == num;
//}
//
//void testIsPerfectSquare()
//{
//    cout << (isPerfectSquare(16) ? "T" : "F") << endl;
//    cout << (isPerfectSquare(14) ? "T" : "F") << endl;
//}
//
//int main()
//{
//    testIsPerfectSquare();
//
//    getchar();
//    return 0;
//}