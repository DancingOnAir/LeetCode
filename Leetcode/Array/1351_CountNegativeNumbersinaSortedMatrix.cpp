#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (auto& r : grid) {
            for (auto& c : r) {
                if (c < 0)
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