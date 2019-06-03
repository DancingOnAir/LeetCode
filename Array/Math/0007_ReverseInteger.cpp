//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int reverse(int x)
//{
//    bool isNegative = false;
//    if (x < 0)
//        isNegative = true;
//
//    string s = to_string(x);
//
//    std::reverse(s.begin(), s.end());
//    try
//    {
//        int res = isNegative ? -stoi(s) : stoi(s);
//        return res;
//    }
//    catch (exception e)
//    {
//        return 0;
//    }
//}
//
//int reverse2(int x)
//{
//    int res = 0;
//    while (x != 0)
//    {
//        int pop = x % 10;
//        x /= 10;
//
//        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7))
//            return 0;
//        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8))
//            return 0;
//
//        res = res * 10 + pop;
//    }
//
//    return res;
//}
//
//void testReverse()
//{
//    cout << reverse(123) << endl;
//    cout << reverse(-123) << endl;
//    cout << reverse(120) << endl;
//}
//
//int main()
//{
//    testReverse();
//    getchar();
//    return 0;
//}