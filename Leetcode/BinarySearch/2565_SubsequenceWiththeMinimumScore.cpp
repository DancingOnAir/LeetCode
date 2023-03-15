#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int minimumScore(string s, string t) {
        int l1 = s.size(), l2 = t.size();
        vector<int> suf(l1 + 1, l2);
        int j = l2 - 1;
        for (int i = l1 - 1; i >= 0; --i) {
            if (j >= 0 && s[i] == t[j]) {
                --j;
            }

            suf[i] = j + 1;
        }

        int res = suf[0];
        if (res == 0) {
            return res;
        }

        j = 0;
        for (int i = 0; i < l1; ++i) {
            if (s[i] == t[j]) {
                res = min(res, suf[i + 1] - j - 1);
                ++j;
            }
        }

        return res;
    }
};

void testMinimumScore() {
    Solution solution;
    cout << solution.minimumScore("abacaba", "bzaa") << endl;
    cout << solution.minimumScore("cde", "xyz") << endl;
}

int main() {
    testMinimumScore();
    return 0;
}