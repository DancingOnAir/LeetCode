//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isSelfCrossing(vector<int>& x) {
//    int len = x.size();
//    if (len < 4)
//        return false;
//
//    for (int i = 3; i < len; ++i)
//    {
//        if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
//            return true;
//
//        if (i >= 4)
//        {
//            if (x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
//                return true;
//        }
//
//        if (i >= 5)
//        {
//            if (x[i - 2] > x[i - 4] && x[i] + x[i - 4] >= x[i - 2] &&
//                x[i - 1] < x[i - 3] && x[i - 1] + x[i - 5] >= x[i - 3])
//                return true;
//        }
//    }
//
//    return false;
//}
//
//void testIsSelfCrossing()
//{
//    vector<int> x1{ 2, 1, 1, 2 };
//    cout << (isSelfCrossing(x1) ? "True" : "False") << endl;
//
//    vector<int> x2{ 1, 2, 3, 4 };
//    cout << (isSelfCrossing(x2) ? "True" : "False") << endl;
//
//    vector<int> x3{ 1, 1, 1, 1 };
//    cout << (isSelfCrossing(x3) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testIsSelfCrossing();
//
//    getchar();
//    return 0;
//}