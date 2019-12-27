//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int power(int x, int n, int mod)
//{
//    int res = 1;
//    for (x %= mod; n; x = x * x % mod, n >>= 1)
//        if (n & 1)
//            res = res * x % mod;
//
//    return res;
//}
//
//// Fermat's Little Theorem
//int superPow2(int a, vector<int>& b)
//{
//    // phi(1337) = phi(7) * phi(191) = 6 * 190 = 1140
//    if (!(a % 1337))
//        return 0;
//
//    int p = 0;
//    for (int i : b)
//        p = (p * 10 + i) % 1140;
//
//    if (p == 0)
//        p = 1440;
//
//    return power(a, p, 1337);
//}
//
//int powmod(int a, int k)
//{
//    a %= 1337;
//    int result = 1;
//
//    for (int i = 0; i < k; ++i)
//        result = (result * a) % 1337;
//
//    return result;
//}
//
//int superPow(int a, vector<int>& b)
//{
//    if (b.empty())
//        return 1;
//
//    int lastDigit = b.back();
//    b.pop_back();
//
//    return powmod(superPow(a, b), 10) * powmod(a, lastDigit) % 1337;
//}
//
//void testSuperPow()
//{
//    vector<int> b1 = { 3 };
//    cout << superPow(2, b1) << endl;
//
//    vector<int> b2 = { 1, 0 };
//    cout << superPow(2, b2) << endl;
//}
//
//int main()
//{
//    testSuperPow();
//    getchar();
//    return 0;
//}