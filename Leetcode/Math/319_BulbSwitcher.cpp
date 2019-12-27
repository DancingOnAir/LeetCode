//#include <iostream>
//
//using namespace std;
//
//int bulbSwitch(int n)
//{
//    if (n < 1)
//        return 0;
//
//    return sqrt(n);
//}
//
//int bulbSwitch2(int n)
//{
//    if (n < 1)
//        return 0;
//
//    int count = 0;
//    for (int i = 1; i * i <= n; ++i)
//        ++count;
//
//    return count;
//}
//
//void testBulbSwitch()
//{
//    cout << bulbSwitch(3) << endl;
//}
//
//int main()
//{
//    testBulbSwitch();
//    getchar();
//    return 0;
//}