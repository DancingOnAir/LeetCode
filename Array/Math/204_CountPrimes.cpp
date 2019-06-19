//#include <iostream>
//#include <math.h>
//#include <vector>
//using namespace std;
//
//int countPrimes(int n)
//{
//    if (n <= 2)
//        return 0;
//
//    int res = 0;
//    for (int i = 2; i < n; ++i)
//    {
//        bool isPrime = true;
//        for (int j = 2; j * j <= i; ++j)
//        {
//            if (0 == i % j)
//            {
//                isPrime = false;
//                break;
//            }
//        }
//
//        if (isPrime)
//            ++res;
//    }
//
//    return res;
//}
//
//int countPrimes2(int n)
//{
//    if (n < 3)
//        return 0;
//
//    vector<bool> isComposite(n, false);
//    int res = 1;
//    for (int i = 3; i < n; i += 2)
//    {
//        if (!isComposite[i])
//        {
//            ++res;
//            if (i > sqrt(n))
//                continue;
//
//            for (int j = i * i; j < n; j += (i << 1))
//            {
//                isComposite[j] = true;
//            }
//        }
//    }
//
//    return res;
//}
//
//void testCountPrimes()
//{
//    cout << countPrimes2(10) << endl;
//    cout << countPrimes2(12) << endl;
//}
//
//int main()
//{
//    testCountPrimes();
//
//    getchar();
//    return 0;
//}