#include <string>

using namespace std;
class Solution {
public:
    int minTimeToType(string word) {
        int res = word.size();
        char prev = 'a';

        for (char c : word) {
            int diff = abs(c - prev);
            res += min(diff, 26 - diff);

            prev = c;
        }

        return res;
    }
};

void testMinTimeToType() {
    Solution solution;

    assert(solution.minTimeToType("abc") == 5);
    assert(solution.minTimeToType("bza") == 7);
    assert(solution.minTimeToType("zjpc") == 34);
}

int main() {
    testMinTimeToType();

    return 0;
}