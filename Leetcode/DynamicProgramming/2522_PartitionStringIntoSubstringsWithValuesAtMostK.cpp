#include <iostream>
#include <string>
#include <vector>


using namespace std;
class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 1e6);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            long long tot = 0, q = 1;
            for (int j = i - 1; j >= 0; --j) {
                tot += (s[j] - '0') * q;
                q *= 10;

                if (tot > k)
                    break;
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[n] == 1e6? -1 : dp[n];
    }
};

void testMinimumPartition() {
    Solution solution;
    cout << solution.minimumPartition("165462", 60) << endl;
    cout << solution.minimumPartition("238182", 5) << endl;
}

int main() {
    testMinimumPartition();
    return 0;
}