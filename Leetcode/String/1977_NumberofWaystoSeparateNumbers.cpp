#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int numberOfCombinations(string num) {
        if (num[0] == '0')
            return 0;

        int n = num.size();
        int res = 0;
        int mod = 1e9 + 7;
        // Let lcp[i][j] be the length of the longest common prefix of num[i..(N-1)] and num[j..(N-1)]
        // Let dp[i][j] be the number of ways to split num[0..j] with the last number starting at index i (0 <= i <= j < N).
        // If i - k < j + 1 - i, we add dp[k][i-1] to dp[i][j]. So dp[i][j] += sum( dp[k][i-1] | max(0, 2*i-j) <= k < i )
        // dp[i][j] = sum( dp[k][i-1] | max(0, 2*i-j) <= k < i )                        // Case 1
        //            + (k == 2*i-j-1 && num[k..(i-1)] <= num[i..j] ? dp[k][i-1] : 0)   // Case 2
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (num[i] == num[j])
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }

        auto le = [&](int k, int i, int j) {
            int len = lcp[k][i];
            return len >= j + 1 - i || num[k + len] < num[i + len];
        };

        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            if (num[i] == '0')
                continue;

            for (int j = i, k = i - 1, sum = 0; j < n; ++j) {
                dp[i][j] = sum;

                if (k < 0)
                    continue;

                if (num[k] > '0' && le(k, i, j))
                    dp[i][j] = (dp[i][j] + dp[k][i - 1]) % mod;
                sum = (sum + dp[k][i - 1]) % mod;
                --k;
            }
        }

        for (int i = 0; i < n; ++i) {
            res = (res + dp[i][n - 1]) % mod;
        }

        return res;
    }
};

void testNumberOfCombinations() {
    Solution solution;

    assert(solution.numberOfCombinations("327") == 2);
    assert(solution.numberOfCombinations("094") == 0);
    assert(solution.numberOfCombinations("0") == 0);
    assert(solution.numberOfCombinations("9999999999999") == 101);
}

int main() {
    testNumberOfCombinations();

    return 0;
}