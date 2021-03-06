#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives1(vector<vector<int>>& grid) {
        int res = 0;
        for (auto& r : grid) {
            res += upper_bound(r.rbegin(), r.rend(), -1) - r.rbegin();
        }

        return res;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = grid.size() - 1; i >= 0 && grid[i].back() < 0; --i) {
            for (int j = grid[0].size() - 1; j >= 0 && grid[i][j] < 0; --j) {
                ++res;
            }
        }

        return res;
    }
};

void testCountNegatives() {
    Solution solution;

    vector<vector<int>> grid1 = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout << solution.countNegatives(grid1) << endl;

    vector<vector<int>> grid2 = {{3,2},{1,0}};
    cout << solution.countNegatives(grid2) << endl;

    vector<vector<int>> grid3 = {{1,-1},{-1,-1}};
    cout << solution.countNegatives(grid3) << endl;

    vector<vector<int>> grid4 = {{-1}};
    cout << solution.countNegatives(grid4) << endl;
}

int main() {
    testCountNegatives();

    return 0;
}