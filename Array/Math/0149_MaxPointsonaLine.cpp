#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxPoints(vector<vector<int>>& points)
{
    int m = points.size();
    if (0 == m)
        return 0;

    int n = points[0].size();
    if (n != 2)
        return 0;

    if (m < 3)
        return m;

    int res = 0;
    unordered_map<double, int> records;
    for (int i = 0; i < m; ++i)
    {
        int horizontal = 0;
        int localMax = 0;
        int overlap = 0;
        records.clear();

        for (int j = 0; j < m; ++j)
        {
            if (i == j)
                continue;

            double k = 0;

            if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
            {
                ++overlap;
            }
            else if (points[i][1] == points[j][1])
            {
                ++horizontal;
            }
            else
            {
                k = (double)(points[j][0] - points[i][0]) / (double)(points[j][1] - points[i][1]);
                records[k]++;

                localMax = max(localMax, records[k]);
            }

            localMax = max(localMax, horizontal);
        }

        res = max(res, localMax + overlap + 1);
    }

    return res;
}

void testMaxPoints()
{
    vector<vector<int>> points1 = { {1,1},{2,2},{3,3} };
    vector<vector<int>> points2 = { {1,1},{3,2},{5,3},{4,1},{2,3},{1,4} };
    vector<vector<int>> points3 = { {2,3 }, { 3,3 }, { -5,3 } };

    cout << maxPoints(points3) << endl;
    cout << maxPoints(points1) << endl;
    cout << maxPoints(points2) << endl;
}

int main()
{
    testMaxPoints();

    getchar();
    return 0;
}