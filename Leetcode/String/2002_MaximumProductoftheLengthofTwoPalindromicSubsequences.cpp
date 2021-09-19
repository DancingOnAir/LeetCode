#include <string>

using namespace std;
class Solution {
private:
    int getLongestPalindrome(string& s, int mask) {
        int res = 0;
        int left = 0, right = s.size();
        while (left <= right) {
            if ((mask & (1 << left)) == 0) {
                ++left;
            }
            // Warning: based on the operator == is higher priority than &
            // (mask & (1 << right) == 0) is wrong, it equals (1 << right) == 0, always false
            else if ((mask & (1 << right)) == 0) {
                --right;
            }
            else if (s[left] != s[right]) {
                return 0;
            }
            else {
                res += 1 + (left++ != right--);
            }
        }
        return res;
    }

public:
    int maxProduct(string s) {
        int dp[4096] = {};
        int res = 0;
        int mask = (1 << s.size()) - 1;

        for (int i = 1; i <= mask; ++i) {
            dp[i] = getLongestPalindrome(s, i);
        }

        // Submask Enumeration
        // https://cp-algorithms.com/algebra/all-submasks.html
        for (int m1 = mask; m1; --m1) {
            if (dp[m1] * (s.size() - dp[m1]) > res) {
                for (int m2 = m1 ^ mask; m2; m2 = (m2 - 1) & (m1 ^ mask)) {
                    res = max(res, dp[m1] * dp[m2]);
                }
            }
        }
        return res;
    }
};

void testMaxProduct() {
    Solution solution;

    assert(solution.maxProduct("leetcodecom") == 9);
    assert(solution.maxProduct("bb") == 1);
    assert(solution.maxProduct("accbcaxxcxx") == 25);
}

int main() {
    testMaxProduct();

    return 0;
}