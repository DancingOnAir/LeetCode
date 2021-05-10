#include <string>

using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        int maxDiff = 0xc0c0c0c0;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                ++zeros;
            }
            else {
                ++ones;
            }

            maxDiff = max(maxDiff, zeros - ones);
        }
        return maxDiff + ones + (s[s.size() - 1] == '1');
    }
};

void testMaxScore() {
    Solution solution;
    assert(solution.maxScore("011101") == 5);
    assert(solution.maxScore("00111") == 5);
    assert(solution.maxScore("1111") == 3);
}

int main() {
    testMaxScore();

    return 0;
}