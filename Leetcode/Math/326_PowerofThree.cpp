//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool isPowerOfThree(int n)
//{
//    if (n < 1)
//        return false;
//
//    while (n % 3 == 0)
//    {
//        n /= 3;
//    }
//
//    if (n == 1)
//        return true;
//
//    return false;
//}
//
//bool isPowerOfThree2(int n)
//{
//    return (n > 0) && ((int)pow(3, 15) % n == 0);
//}
//
//void testIsPowerOfThree()
//{
//    cout << (isPowerOfThree2(27) ? "True" : "False") << endl;
//    cout << (isPowerOfThree2(0) ? "True" : "False") << endl;
//    cout << (isPowerOfThree2(9) ? "True" : "False") << endl;
//    cout << (isPowerOfThree2(45) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testIsPowerOfThree();
//
//    getchar();
//    return 0;
//}