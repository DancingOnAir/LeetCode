#include <string>

using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (a < b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString(a, c, b, aa, cc, bb);

        if (0 == b)
            return string(min(2, a), aa);
        int useA = min(2, a), useB = a - useA >= b ? 1 : 0;
        return string(useA, aa) + string(useB, bb) + longestDiverseString(a - useA, b - useB, c, aa, bb, cc);
    }
};

void testLongestDiverseString() {
    Solution solution;

    assert(solution.longestDiverseString(1, 1, 7) == "ccaccbcc");
    assert(solution.longestDiverseString(2, 2, 1) == "aabbc");
    assert(solution.longestDiverseString(7, 1, 0) == "aabaa");
}

int main() {
    testLongestDiverseString();

    return 0;
}