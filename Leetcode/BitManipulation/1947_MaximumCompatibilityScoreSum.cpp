#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int helper(vector<int>& dp, int mask, int i, int n, int m, vector<vector<int>>& students, vector<vector<int>>& mentors) {
        if (i >= n) {
            return 0;
        }

        if (dp[mask] != -1) {
            return dp[mask];
        }

        int res = 0;
        for (int j = 0; j < n; ++j) {
            if ((mask & (1 << j)) > 0) {
                int cur = 0;
                for (int k = 0; k < m; ++k) {
                    cur += (students[i][k] == mentors[j][k]);
                }
                res = max(res, cur + helper(dp, mask ^ (1 << j), i + 1, n, m, students, mentors));
            }
        }

        dp[mask] = res;
        return res;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        auto n = students.size();
        auto m = students[0].size();
        vector<int> dp(1 << n, -1);
        return helper(dp, (1 << n) - 1, 0, n, m, students, mentors);
    }
};


void testMaxCompatibilitySum() {
    Solution solution;
    vector<vector<int>> students1 {{1,1,0},{1,0,1},{0,0,1}};
    vector<vector<int>> mentors1 {{1,0,0},{0,0,1},{1,1,0}};
    cout << solution.maxCompatibilitySum(students1, mentors1) << endl;

    vector<vector<int>> students2 {{0,0},{0,0},{0,0}};
    vector<vector<int>> mentors2 {{1,1},{1,1},{1,1}};
    cout << solution.maxCompatibilitySum(students2, mentors2) << endl;
}


int main() {
    testMaxCompatibilitySum();
    return 0;
}