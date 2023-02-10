#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int countArrangement(int n) {
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int bitmask = 0; bitmask < (1 << n); ++bitmask) {
            int bits = __builtin_popcount(bitmask);
            for (int i = 0; i < n; ++i) {
                if (bitmask & (1 << i) && ((i + 1) % bits == 0 || bits % (i + 1) == 0)) {
                    dp[bitmask] += dp[bitmask ^ (1 << i)];
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};

void testCountArrangement() {
    Solution solution;
    cout << solution.countArrangement(2) << endl;
    cout << solution.countArrangement(1) << endl;
}

int main() {
    testCountArrangement();
    return 0;
}