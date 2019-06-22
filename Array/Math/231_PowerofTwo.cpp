//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool isPowerOfTwo(int n)
//{
//    if (n <= 0)
//        return false;
//
//    return !((n - 1) & n);
//}
//
//bool isPowerOfTwo2(int n)
//{
//    return n > 0 && ((int)pow(2, 30) % n == 0);
//}
//
//void testIsPowerOfTwo()
//{
//    cout << (isPowerOfTwo2(1) ? "T" : "F") << endl;
//    cout << (isPowerOfTwo2(16) ? "T" : "F") << endl;
//    cout << (isPowerOfTwo2(218) ? "T" : "F") << endl;
//    cout << (isPowerOfTwo2(1024) ? "T" : "F") << endl;
//}
//
//int main()
//{
//    testIsPowerOfTwo();
//
//    getchar();
//    return 0;
//}