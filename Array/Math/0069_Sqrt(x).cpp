//#include <iostream>
//
//using namespace std;
//
//int mySqrt(int x)
//{
//    if (x <= 0)
//        return 0;
//
//    double res = 1.0;
//    double epsilon = 1e-4;
//    while (abs(res * res - x) > epsilon)
//    {
//        res = (res + x / res) / 2;
//    }
//
//    return res;
//}
//
//int mySqrt2(int x)
//{
//    if (x <= 0)
//        return 0;
//
//    double left = 0.0, right = x;
//    double epsilon = 1e-4;
//    while (true)
//    {
//        double mid = left + (right - left) / 2;
//        if ((mid * mid - x) > epsilon)
//            right = mid;
//        else if (mid * mid - x < -epsilon)
//            left = mid;
//        else
//            return mid;
//    }
//}
//
//void testMySqrt()
//{
//
//    cout << mySqrt2(2) << endl;
//    cout << mySqrt2(3) << endl;
//    cout << mySqrt2(4) << endl;
//    cout << mySqrt2(8) << endl;
//}
//
//int main()
//{
//    testMySqrt();
//
//    getchar();
//    return 0;
//}