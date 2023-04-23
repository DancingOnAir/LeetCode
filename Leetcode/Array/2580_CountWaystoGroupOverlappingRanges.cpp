#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int res = 1, pre = -1, mod = 1e9 + 7;
        for (auto& r : ranges) {
            if (pre < r[0]) {
                res = res * 2 % mod;
            }

            pre = max(pre, r[1]);
        }

        return res;
    }
};

void testCountWays() {
    Solution solution;
    vector<vector<int>> ranges1 {{6,10},{5,15}};
    cout << solution.countWays(ranges1) << endl;
    vector<vector<int>> ranges2 {{1,3},{10,20},{2,5},{4,8}};
    cout << solution.countWays(ranges2) << endl;
}

int main() {
    testCountWays();
    return 0;
}