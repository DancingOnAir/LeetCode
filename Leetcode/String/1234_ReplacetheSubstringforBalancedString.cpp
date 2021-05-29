#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    // sliding window
    int balancedString(string s) {
        unordered_map<char, int> m;
        int res = s.size();
        int n = s.size();
        for (char c : s) {
            ++m[c];
        }

        for (int i = 0, j = 0; i < n; ++i) {
            --m[s[i]];
            while (j < n && all_of(m.begin(), m.end(), [&](const pair<char, int>& p) { return p.second <= n/4; })) {
                res = min(res, i + 1 - j);
                ++m[s[j++]];
            }
        }

        return res;
    }
};

void testBalancedString() {
    Solution solution;

    assert(solution.balancedString("QWER") == 0);
    assert(solution.balancedString("QQWE") == 1);
    assert(solution.balancedString("QQQW") == 2);
    assert(solution.balancedString("QQQQ") == 3);
}

int main() {
    testBalancedString();

    return 0;
}