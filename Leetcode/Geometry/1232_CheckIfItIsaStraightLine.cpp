//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool checkStraightLine2(vector<vector<int>>& coordinates)
//{
//    int n = coordinates.size();
//    int k = INT_MIN;
//    for (int i = 1; i < n; ++i)
//    {
//        double x = coordinates[i][0] - coordinates[i - 1][0];
//        double y = coordinates[i][1] - coordinates[i - 1][1];
//        double cur = (x != 0 ? y / x : INT_MAX);
//        
//        if (k == INT_MIN)
//            k = cur;
//        else if (k != cur)
//            return false;
//    }
//
//    return true;
//}
//
//bool checkStraightLine(vector<vector<int>>& coordinates)
//{
//    for (int i = 0; i < coordinates.size() - 2; ++i)
//    {
//        auto p0 = coordinates[i];
//        auto p1 = coordinates[i + 1];
//        auto p2 = coordinates[i + 2];
//
//        if ((p2[1] - p0[1]) * (p1[0] - p0[0]) != (p1[1] - p0[1]) * (p2[0] - p0[0]))
//            return false;
//    }
//
//    return true;
//}
//
//void testCheckStraightLine()
//{
//    vector<vector<int>> coordinates1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
//    cout << (checkStraightLine(coordinates1) ? "True" : "False") << endl;
//
//    vector<vector<int>> coordinates2 = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
//    cout << (checkStraightLine(coordinates2) ? "True" : "False") << endl;
//
//    vector<vector<int>> coordinates3 = { {-4, -3}, {1, 0}, {3, -1}, {0, -1}, {-5, 2} };
//    cout << (checkStraightLine(coordinates3) ? "True" : "False") << endl;
//}
//
//int main()
//{
//    testCheckStraightLine();
//
//    getchar();
//    return 0;
//}