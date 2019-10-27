#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int leastBricks(vector<vector<int>>& wall)
{
    unordered_map<int, int> count;
    int res = 0;

    for (int i = 0; i < wall.size(); ++i)
    {
        int sum = 0;
        for (int j = 0; j + 1 < wall[i].size(); ++j)
        {
            count[sum += wall[i][j]]++;
            res = max(res, count[sum]);
        }
    }

    return wall.size() - res;
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