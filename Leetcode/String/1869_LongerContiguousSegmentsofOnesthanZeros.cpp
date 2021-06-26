#include <string>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int cnt[2] = {0, 0};
        for (int i = 0, j = 0; j < s.size(); j = i) {
            while (i < s.size() && s[i] == s[j]) {
                cnt[s[j] - '0'] = max(cnt[s[j] - '0'], ++i - j);
            }
        }
        return cnt[0] < cnt[1];
    }
};

void testCheckZeroOnes() {
    Solution solution;

    assert(solution.checkZeroOnes("1101"));
    assert(!solution.checkZeroOnes("111000"));
    assert(!solution.checkZeroOnes("110100010"));
}

int main() {
    testCheckZeroOnes();

    return 0;
}