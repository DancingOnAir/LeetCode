#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long> dp(26);
        long MOD = 1e9 + 7;
        for (char& c : s) {
            dp[c - 'a'] = accumulate(dp.begin(), dp.end(), 1L) % MOD;
        }

        return accumulate(dp.begin(), dp.end(), 0L) % MOD;
    }
};

void testDistinctSubseqII() {
    Solution solution;

    assert(solution.distinctSubseqII("abc") == 7);
    assert(solution.distinctSubseqII("aba") == 6);
    assert(solution.distinctSubseqII("aaa") == 3);
}

int main() {
    testDistinctSubseqII();

    return 0;
}