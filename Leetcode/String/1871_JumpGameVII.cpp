#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1')
            return false;

        vector<bool> dp(s.size(), false);
        dp[0] = true;
        int pre = 0;

        for (auto i = 1; i < s.size(); ++i) {
            if (i >= minJump)
                pre += dp[i - minJump];
            if (i > maxJump)
                pre -= dp[i - maxJump - 1];
            dp[i] = (pre > 0) && s[i] == '0';
        }

        return dp.back();
    }
};

void testCanReach() {
    Solution solution;
    assert(solution.canReach("011010", 2, 3));
    assert(!solution.canReach("01101110", 2, 3));
}

int main() {
    testCanReach();

    return 0;
}