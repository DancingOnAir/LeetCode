//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minTimeToVisitAllPoints(vector<vector<int>>& points)
//{
//    int res = 0;
//    for (int i = 0; i < points.size() - 1; ++i)
//    {
//        int x = abs(points[i + 1][0] - points[i][0]);
//        int y = abs(points[i + 1][1] - points[i][1]);
//        res += max(x, y);
//    }
//
//    return res;
//}
//
//void testMinTimeToVisitAllPoints()
//{
//    vector<vector<int>> points1 = { {1, 1},{3, 4},{-1, 0 } };
//    cout << minTimeToVisitAllPoints(points1) << endl;
//}
//
//int main()
//{
//    testMinTimeToVisitAllPoints();
//
//    getchar();
//    return 0;
//}