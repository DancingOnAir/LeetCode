#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        auto n = tasks.size();
        auto m = 1 << n;
        vector<int> dp(m, n);
        for (auto i = 1; i < m; ++i) {
            int consuming = 0;
            int j = i;
            int idx = 0;
            while (j > 0) {
                if (j & 1) {
                    consuming += tasks[idx];
                }
                ++idx;
                j >>= 1;
            }

            if (consuming <= sessionTime) {
                dp[i] = 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            if (dp[i] == 1)
                continue;

            int split = i >> 1;
            for (int j = (i - 1) & i; j > split; j = i & (j - 1)) {
                dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
            }
        }
        return dp[m - 1];
    }
};

void testMinSessions() {
    Solution solution;
    vector<int> tasks1 {1, 2, 3};
    cout << solution.minSessions(tasks1, 3) << endl;
    vector<int> tasks2 {3, 1, 3, 1, 1};
    cout << solution.minSessions(tasks2, 8) << endl;
    vector<int> tasks3 {1, 2, 3, 4, 5};
    cout << solution.minSessions(tasks3, 15) << endl;
}

int main() {
    testMinSessions();
    return 0;
}