//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
//int calcDistance(vector<int>& p1, vector<int>& p2)
//{
//    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
//}
//
//bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
//{
//    unordered_set<int> ps({ calcDistance(p1, p2), calcDistance(p1, p3), calcDistance(p1, p4), calcDistance(p2, p3), calcDistance(p2, p4), calcDistance(p3, p4) });
//
//    return !ps.count(0) && 2 == ps.size();
//}
//
//void testValidSquare()
//{
//    vector<int> p1 = { 0, 0 };
//    vector<int> p2 = { 1, 1 };
//    vector<int> p3 = { 1, 0 };
//    vector<int> p4 = { 0, 1 };
//    cout << (validSquare(p1, p2, p3, p4) ? "True": "False") << endl;
//}
//
//int main()
//{
//    testValidSquare();
//
//    getchar();
//    return 0;
//}