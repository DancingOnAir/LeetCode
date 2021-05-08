#include <string>

using namespace std;
class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++cur;
                res = max(res, cur);
            }
            else {
                cur = 1;
            }
        }

        return res;
    }
};

void testMaxPower() {
    Solution solution;
    assert(solution.maxPower("leetcode") == 2);
    assert(solution.maxPower("abbcccddddeeeeedcba") == 5);
    assert(solution.maxPower("triplepillooooow") == 5);
    assert(solution.maxPower("hooraaaaaaaaaaay") ==11);
    assert(solution.maxPower("tourist") == 1);
}

int main() {
    testMaxPower();

    return 0;
}