//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//int numberOfBoomerangs(vector<vector<int>>& points)
//{
//    int res = 0;
//    for (auto& p : points)
//    {
//        unordered_map<double, int> count(points.size());
//        for (auto&q : points)
//        {
//            double dist = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
//            res += 2 * count[dist]++;
//        }
//    }
//
//    return res;
//}
//
//void testNumberOfBoomerangs()
//{
//    vector<vector<int>> points1 = { {0, 0}, { 1, 0}, { 2, 0 } };
//    cout << numberOfBoomerangs(points1) << endl;
//
//    vector<vector<int>> points2 = { {0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//    cout << numberOfBoomerangs(points2) << endl;
//}
//
//int main()
//{
//    testNumberOfBoomerangs();
//
//    getchar();
//    return 0;
//}