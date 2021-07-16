#include <string>

using namespace std;
class Solution {
public:
    // two pointers solution
    int minimumLength(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi && s[lo] == s[hi]) {
            char c = s[lo];
            while (lo <= hi && c == s[lo])
                ++lo;
            while (lo <= hi && c == s[hi])
                --hi;
        }

        return hi - lo + 1;
    }
};

void testMinimumLength() {
    Solution solution;

    assert(solution.minimumLength("ca") == 2);
    assert(solution.minimumLength("cabaabac") == 0);
    assert(solution.minimumLength("aabccabba") == 3);
}

int main() {
    testMinimumLength();

    return 0;
}