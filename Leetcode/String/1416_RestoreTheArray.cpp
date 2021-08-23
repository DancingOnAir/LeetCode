#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        long long mod = 1e9 + 7;
        int m = to_string(k).size();
        int n = s.size();
        vector<long long> dp(n + 1);
        dp[0] = 1;

        for (int i = 0; i < n + 1; ++i) {
            long long num = 0, base = 1;
            for (int j = i - 1; j >= max(0, i - m); --j) {
                num += (s[j] - '0') * base;
                if (num > k)
                    break;
                if (s[j] != '0')
                    dp[i] += dp[j] % mod;
                base *= 10;
            }

            dp[i] %= mod;
        }

        return dp[n];
    }
};

void testNumberOfArrays() {
    Solution solution;

    assert(solution.numberOfArrays("1000", 1000) == 1);
    assert(solution.numberOfArrays("1000", 10) == 0);
    assert(solution.numberOfArrays("1317", 2000) == 8);
    assert(solution.numberOfArrays("2020", 30) == 1);
    assert(solution.numberOfArrays("1234567890", 90) == 34);
}

int main() {
    testNumberOfArrays();

    return 0;
}