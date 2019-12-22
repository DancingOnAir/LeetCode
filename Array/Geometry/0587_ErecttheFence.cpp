#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Convex Hull: Andrew's Monotone Chain
double d2(const vector<int>& p1, const vector<int>& p2)
{
    return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
}

int cross(const vector<int>& o, const vector<int>& a, const vector<int>& b)
{
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
}

bool cmp(const vector<int>& lhs, const vector<int>& rhs)
{
    return (lhs[0] < rhs[0]) || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
}

vector<vector<int>> outerTrees(vector<vector<int>>& points)
{
    int n = points.size();
    if (n < 4)
    return points;

    sort(points.begin(), points.end(), cmp);
    int count = 0;
    
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i)
    {
        while (count >= 2 && cross(points[count - 2], points[count - 1], points[i]) <= 0)
            --count;
        res[count].emplace_back(points[i]);
    }


}

void display(const vector<vector<int>>& points)
{
    for (auto& p : points)
        cout << p[0] << ", " << p[1] << endl;
}

void testOuterTrees()
{
    vector<vector<int>> points1 = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
    auto res1 = outerTrees(points1);
    display(res1);

    vector<vector<int>> points2 = { {1, 2},{2, 2},{4, 2} };
    auto res2 = outerTrees(points2);
    display(res2);
}

int main()
{
    testOuterTrees();
    getchar();
    return 0;
}