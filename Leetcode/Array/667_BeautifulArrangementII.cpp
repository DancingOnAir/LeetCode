//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> constructArray(int n, int k)
//{
//    vector<int> res;
//
//    for (int i = 1, j = n; i <= j;)
//    {
//        if (k > 1)
//        {
//            res.emplace_back(k-- % 2? i++:j--);
//        }
//        else
//            res.emplace_back(i++);
//    }
//
//    return res;
//}
//
//void testConstructArray()
//{
//    auto res = constructArray(4, 3);
//    for (auto x : res)
//        cout << x << ", ";
//    cout << endl;
//}
//
//int main()
//{
//    testConstructArray();
//    getchar();
//    return 0;
//}