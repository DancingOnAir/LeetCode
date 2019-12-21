//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//double minAreaFreeRect(vector<vector<int>>& points)
//{
//    int n = points.size();
//    if (n < 4)
//        return 0;
//
//    double res = DBL_MAX;
//    for (int i = 0; i < n - 1; ++i)
//    {
//        for (int j = i + 1; j < n; ++j)
//        {
//            for (int a = 0; a < n; ++a)
//            {
//                if (a == i || a == j)
//                    continue;
//
//                if ((points[i][1] - points[j][1]) * (points[a][1] - points[i][1]) == -(points[i][0] - points[j][0]) * (points[a][0] - points[i][0]))
//                {
//                    for (int b = 0; b < n; ++b)
//                    {
//                        if (b == i || b == j || b == a)
//                            continue;
//
//                        if ((points[i][1] - points[j][1]) * (points[b][1] - points[j][1]) == -(points[i][0] - points[j][0]) * (points[b][0] - points[j][0]))
//                        {
//                            if ((points[i][0] - points[j][0]) * (points[b][1] - points[a][1]) == (points[i][1] - points[j][1]) * (points[b][0] - points[a][0]))
//                            {
//                                double x = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
//                                double y = (points[b][0] - points[j][0]) * (points[b][0] - points[j][0]) + (points[b][1] - points[j][1]) * (points[b][1] - points[j][1]);
//                                double s = sqrt(x * y);
//                                res = res < s ? res : s;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    return res == numeric_limits<double>::max() ? 0: res;
//}
//
//void testMinAreaFreeRect()
//{
//    vector<vector<int>> points1 = {{1, 2}, {2, 1}, {1, 0}, {0, 1}};
//    cout << minAreaFreeRect(points1) << endl;
//
//    vector<vector<int>> points2 = {{0, 1}, {2, 1}, {1, 1}, {1, 0}, {2, 0}};
//    cout << minAreaFreeRect(points2) << endl;
//
//    vector<vector<int>> points3 = {{0, 3}, {1, 2}, {3, 1}, {1, 3}, {2, 1}};
//    cout << minAreaFreeRect(points3) << endl;
//
//    vector<vector<int>> points4 = {{3, 1}, {1, 1}, {0, 1}, {2, 1}, {3, 3}, {3, 2}, {0, 2}, {2, 3}};
//    cout << minAreaFreeRect(points4) << endl;
//}
//
//int main()
//{
//    testMinAreaFreeRect();
//
//    getchar();
//    return 0;
//}