#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod = 1e9 + 7;
        vector<int> dp(2);

        for (auto& ch : binary) {
            dp[ch - '0'] = (dp[0] + dp[1] + (ch - '0')) % mod;
        }

        return (dp[0] + dp[1] + (binary.find('0') != string::npos)) % mod;
    }
};

void testNumberOfUniqueGoodSubsequences() {
    Solution solution;
    assert(solution.numberOfUniqueGoodSubsequences("001") == 2);
    assert(solution.numberOfUniqueGoodSubsequences("11") == 2);
    assert(solution.numberOfUniqueGoodSubsequences("101") == 5);
}

int main() {
    testNumberOfUniqueGoodSubsequences();

    return 0;
}