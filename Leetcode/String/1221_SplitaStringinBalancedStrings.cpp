#include <string>

using std::string;

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cnt = 0;
        for (char c : s) {
            if (c == 'L')
                ++cnt;
            else
                --cnt;

            if (cnt == 0)
                ++res;
        }

        return res;
    }
};

void testBalancedStringSplit() {
    Solution solution;

    assert(solution.balancedStringSplit("RLRRLLRLRL") == 4);
    assert(solution.balancedStringSplit("RLLLLRRRLR") == 3);
    assert(solution.balancedStringSplit("LLLLRRRR") == 1);
    assert(solution.balancedStringSplit("RLRRRLLRLL") == 2);
}

int main() {
    testBalancedStringSplit();

    return 0;
}