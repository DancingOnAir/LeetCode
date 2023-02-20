#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int j = upper_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k - 1) - prizePositions.begin();
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, dp[j] + i - j + 1);
        }

        return res;
    }
};

void testMaximizeWin() {
    Solution solution;
    vector<int> p1 {1,1,2,2,3,3,5};
    cout << solution.maximizeWin(p1, 2) << endl;
    vector<int> p2 {1,2,3,4};
    cout << solution.maximizeWin(p2, 0) << endl;
}

int main() {
    testMaximizeWin();
    return 0;
}