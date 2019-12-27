//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int gcd(int lhs, int rhs)
//{
//    return rhs ? gcd(rhs, lhs % rhs) : lhs;
//}
//
//bool canMeasureWater(int x, int y, int z)
//{
//    if (x + y < z)
//        return false;
//    
//    if (x == z || y == z || x + y == z)
//        return true;
//
//    return !(z % gcd(x, y));
//}
//
//void testCanMeasureWater()
//{
//    cout << (canMeasureWater(3, 5, 4)? "T" : "F") << endl;
//    cout << (canMeasureWater(2, 6, 5) ? "T" : "F") << endl;
//}
//
//int main()
//{
//    testCanMeasureWater();
//
//    getchar();
//    return 0;
//}