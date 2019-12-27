//#include <iostream>
//#include <math.h>
//#include <unordered_set>
//#include <string>
//using namespace std;
//
//bool isHappy(int n)
//{
//    if (n < 1)
//        return false;
//
//    if (1 == n)
//        return true;
//
//    unordered_set<int> s;
//
//    while (1 != n)
//    {
//        string num = to_string(n);
//        int sum = 0;
//        for (char c : num)
//        {
//            sum += (c - '0') * (c - '0');
//        }
//
//        n = sum;
//        if (s.count(n))
//            return false;
//        s.insert(n);
//    }
//
//    return true;
//}
//
//void testIsHappy()
//{
//    cout << (isHappy(19) ? "T" : "F") << endl;
//    cout << (isHappy(2) ? "T" : "F") << endl;
//}
//
//int main()
//{
//    testIsHappy();
//
//    getchar();
//    return 0;
//}