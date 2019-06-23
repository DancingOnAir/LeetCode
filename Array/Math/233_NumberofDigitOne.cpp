//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int countDigitOne(int n)
//{
//    if (n < 1)
//        return 0;
//    
//    int res = 0;
//    
//    for (long long m = 1; m <= n; m *= 10)
//    {
//        int a = n / m;
//        int b = n % m;
//
//        res += ((a + 8) / 10) * m + (a % 10 == 1) * (b + 1);
//    }
//
//    return res;
//}
//
//void testCountDigitOne()
//{
//    cout << countDigitOne(13) << endl;
//}
//
//int main()
//{
//    testCountDigitOne();
//
//    getchar();
//    return 0;
//}