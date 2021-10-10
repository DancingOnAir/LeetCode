#include <string>

using namespace std;
class Solution {
public:
    int minimumMoves(string s) {
        int res = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == 'X') {
                i += 3;
                ++res;
            }
            else {
                ++i;
            }
        }

        return res;
    }
};

void testMinimumMoves() {
    Solution soluion;
    assert(soluion.minimumMoves("XXX") == 1);
    assert(soluion.minimumMoves("XXOX") == 2);
    assert(soluion.minimumMoves("OOOO") == 0);
}

int main() {
    testMinimumMoves();

    return 0;
}