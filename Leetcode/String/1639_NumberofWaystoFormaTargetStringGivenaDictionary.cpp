#include <vector>
#include <string>


using namespace std;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9 + 7;
        int n = words.size(), l1 = words[0].size(), l2 = target.size();
        vector<vector<long>> cnt(l1, vector<long>(26));

        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < n; ++j) {
                ++cnt[i][words[j][i] - 'a'];
            }
        }

        vector<vector<long>> dp(l1 + 1, vector<long>(l2 + 1));
        for (int i = 0; i < l1; ++i) {
            dp[i][0] = 1;
            for (int j = 0; j < i + 1 && j < l2; ++j) {
                dp[i + 1][j + 1] = (dp[i][j + 1] + (dp[i][j] * cnt[i][target[j] - 'a']) % mod) % mod;
            }
        }

        return dp[l1][l2];
    }
};

void testNumWays() {
    Solution solution;

    vector<string> words1{"acca", "bbbb", "caca"};
    assert(solution.numWays(words1, "aba") == 6);

    vector<string> words2{"abba", "baab"};
    assert(solution.numWays(words2, "bab") == 4);

    vector<string> words3{"abcd"};
    assert(solution.numWays(words3, "abcd") == 1);

    vector<string> words4{"abab", "baba", "abba", "baab"};
    assert(solution.numWays(words4, "abba") == 16);
}

int main() {
    testNumWays();

    return 0;
}
