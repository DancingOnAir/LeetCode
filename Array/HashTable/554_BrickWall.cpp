#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int leastBricks(vector<vector<int>>& wall)
{
    unordered_map<int, int> count;
    int res = INT_MIN;
    int row = wall.size();

    for (int i = 0; i < row; ++i)
    {
        int tmp = 0;
        for (int j = 0; j < wall[i].size(); ++j)
        {
            tmp += wall[i][j];
            if (j != wall[i].size() - 1)
            {
                ++count[tmp];
                res = max(res, count[tmp]);
            }

        }
    }

    return (count.size() == 0)? row : (row - res);
}

void testLeastBricks()
{
    vector<vector<int>> wall1 = {{1, 2, 2, 1},
                                {3, 1, 2},
                                {1, 3, 2},
                                {2, 4},
                                {3, 1, 2},
                                {1, 3, 1, 1}};

    cout << leastBricks(wall1) << endl;
    
    vector<vector<int>> wall2 = { {1},
                            {1},
                            {1} };

    cout << leastBricks(wall2) << endl;
}

int main()
{
    testLeastBricks();

    getchar();
    return 0;
}