#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string w = word1 + word2;
        int n1 = word1.size();
        int n = w.size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (w[i] == w[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (i < n1 && j >= n1) {
                        res = max(res, dp[i][j]);
                    }
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return res;
    }
};

void testLongestPalindrome() {
    Solution solution;

    assert(solution.longestPalindrome("cacb", "cbba") == 5);
    assert(solution.longestPalindrome("ab", "ab") == 3);
    assert(solution.longestPalindrome("aa", "bb") == 0);
}

int main() {
    testLongestPalindrome();

    return 0;
}