#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    // KMP
    string longestPrefix(string s) {
        vector<int> dp(s.size());
        int j = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[j]) {
                dp[i] = ++j;
            }
            else if (j > 0){
                j = dp[j - 1];
                --i;
            }
        }

        return s.substr(0, j);
    }
};

void testLongestPrefix() {
    Solution solution;
    assert(solution.longestPrefix("level") == "l");
    assert(solution.longestPrefix("ababab") == "abab");
    assert(solution.longestPrefix("leetcodeleet") == "leet");
    assert(solution.longestPrefix("a") == "");
}

int main() {
    testLongestPrefix();

    return 0;
}