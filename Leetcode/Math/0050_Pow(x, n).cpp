//#include <iostream>
//
//using namespace std;
//
//double myPow(double x, int n)
//{
//    if (0 == n)
//        return 1;
//
//    if (n < 0)
//    {
//        if (n == INT_MIN)
//        {
//            n = INT_MAX;
//            x = 1 / x;
//            return x * x * myPow(x * x, n >> 1);
//        }
//
//        n = -n;
//        x = 1 / x;
//    }
//    
//    return (n & 1)? x * myPow(x * x, n >> 1) : myPow(x * x, n >> 1);
//}
//
//double myPow2(double x, int n)
//{
//    if (0 == n)
//        return 1;
//
//    double temp = myPow(x, n / 2);
//    if (n & 1)
//    {
//        return n < 0 ? 1 / x * temp * temp : x * temp * temp;
//    }
//    else
//        return temp * temp;
//}
//
//void testMyPow()
//{
//    cout << myPow(2, 10) << endl;
//    cout << myPow(2.1, 3) << endl;
//    cout << myPow(2, -2) << endl;
//}
//
//int main()
//{
//    testMyPow();
//
//    getchar();
//    return 0;
//}