//#include <iostream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//int getRemaining(long long num, long long base)
//{
//    int res = log(num) / log(base);
//    return res;
//}
//
//string smallestGoodBase2(string n)
//{
//    if (n.empty())
//        return "";
//
//    long long num = atoll(n.c_str());
//    long long res = 2;
//
//    while (res < num)
//    {
//        long long temp = getRemaining(num, res);
//        if ((pow(res, temp + 1) - 1) / (res - 1) == num)
//            return to_string(res);
//        else
//            ++res;
//    }
//
//    return "";
//}
//
//string smallestGoodBase(string n)
//{
//    unsigned long long num = stoll(n);
//    // this loop will iterate length from max possible value to min value
//    // when base == 2, we have longest length of '1'
//    // 2^0 + 2^1 + ... + 2^(len - 1) == num -> 2^len == num + 1 -> len = log(num + 1) base on 2
//    // log(num + 1) / log(2) == log (num + 1) base on 2
//    for (unsigned long long p = log(num + 1) / log(2); p >= 2; --p)
//    {
//        unsigned long long lk = 2, rk = pow(num, 1.0 / (p - 1)) + 1;
//        while (lk < rk)
//        {
//            unsigned long long mk = lk + (rk - lk) / 2, sum = 0;
//            for (unsigned long long i = 0, f = 1; i < p; ++i, f *= mk)
//                sum += f;
//            if (sum < num)
//                lk = mk + 1;
//            else if (sum > num)
//                rk = mk - 1;
//            else
//                return to_string(mk);
//        }
//    }
//
//    return to_string(num - 1);
//}
//
//void testSmallestGoodBase()
//{
//    cout << smallestGoodBase("13") << endl;
//    cout << smallestGoodBase("15") << endl;
//    cout << smallestGoodBase("4681") << endl;
//    cout << smallestGoodBase("1000000000000000000") << endl;
//}
//
//int main()
//{
//    testSmallestGoodBase();
//
//    getchar();
//    return 0;
//}