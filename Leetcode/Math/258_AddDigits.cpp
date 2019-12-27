//#include <iostream>
//#include <string>
//using namespace std;
//
//int addDigits(int num)
//{
//    if (num < 10)
//        return num;
//
//    int sum = 0;
//    while (true)
//    {
//        string s = to_string(num);
//        if (s.size() == 1)
//            return num;
//
//        sum = 0;
//        for (char c : s)
//            sum += c - '0';
//
//        num = sum;
//    }
//    return 0;
//}
//
////digital root
//int addDigits2(int num)
//{
//    if (num < 1)
//        return 0;
//
//    return (num - 1) % 9 + 1;
//}
//
//void testAddDigits()
//{
//    cout << addDigits2(38) << endl;
//}
//
//int main()
//{
//    testAddDigits();
//    getchar();
//    return 0;
//}
//
