//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//class MyCalendar
//{
//public:
//    MyCalendar()
//    {
//
//    }
//
//    bool book(int start, int end)
//    {
//        m[start]++;
//        m[end]--;
//        int sum = 0;
//
//        for (auto& x : m)
//        {
//            sum += x.second;
//            if (sum == 2)
//            {
//                m[start]--;
//                m[end]++;
//                return false;
//            }
//
//        }
//
//        return true;
//    }
//
//private:
//    map<int, int> m;
//};
//
//void testMyCalendar()
//{
//    MyCalendar myCalendar;
//    bool res = myCalendar.book(10, 20);
//    cout << (res ? "true" : "false") << endl;
//
//    res = myCalendar.book(50, 60);
//    cout << (res ? "true" : "false") << endl;
//
//    res = myCalendar.book(10, 40);
//    cout << (res ? "true" : "false") << endl;
//
//    res = myCalendar.book(5, 15);
//    cout << (res ? "true" : "false") << endl;
//
//    res = myCalendar.book(5, 10);
//    cout << (res ? "true" : "false") << endl;
//
//    res = myCalendar.book(25, 55);
//    cout << (res ? "true" : "false") << endl;
//}
//
//int main()
//{
//    testMyCalendar();
//    getchar();
//    return 0;
//}