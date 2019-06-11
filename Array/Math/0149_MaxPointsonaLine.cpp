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
        int numOfHorizontal = 0;
        records.clear();
        for (int j = 0; j < m; ++j)
        {
            if (i == j)
                continue;

            double k = 0;

            if (points[j][1] != points[i][1])
            {
                k = (double)(points[j][0] - points[i][0]) / (double)(points[j][1] - points[i][1]);
                if (records.count(k))
                {
                    records[k]++;
                }
                else
                {
                    records[k] = 2;
                }
            }
            else
            {
                if (numOfHorizontal)
                    ++numOfHorizontal;
                else
                    numOfHorizontal = 2;
            }
        }
        
        int temp = 0;
        for (auto iter = records.begin(); iter != records.end(); ++iter)
        {
            temp = max(temp, iter->second);
        }

        res = max(res, max(temp, numOfHorizontal));
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