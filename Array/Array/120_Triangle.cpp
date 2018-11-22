#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
    if (triangle.empty())
        return 0;

    vector<int> result(triangle.size(), triangle[0][0]);

    for (int i = 1; i < triangle.size(); ++i)
    {
        for (int j = i; j >= 0; --j)
        {
            if (0 == j)
                result[0] += triangle[i][j];
            else if (i == j)
                result[j] = triangle[i][j] + result[j - 1];
            else
                result[j] = triangle[i][j] + min(result[j], result[j - 1]);
        }
    }

    return *min_element(result.begin(), result.end());
}

int minimumTotal2(vector<vector<int>>& triangle)
{
    if (triangle.empty())
        return 0;

    vector<int> path(triangle.back());
    for (int i = triangle.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            path[j] = min(path[j], path[j + 1]) + triangle[i][j];
        }
    }

    return path[0];
}

void testMinimumTotal()
{
    vector<vector<int>> triangle = { {2}, 
                                    {3, 4}, 
                                    { 6, 5, 7 }, 
                                    { 4, 1, 8, 3 } };

    int result = minimumTotal2(triangle);
    cout << result << endl;
}

int main()
{
    testMinimumTotal();
    getchar();
}