#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0, unique = 0;
        vector<int> cnt(26);
        unordered_map<string, int> m;
        int left = 0, right = 0;

        while (right < s.size()) {
            if (++cnt[s[right++] - 'a'] == 1)
                ++unique;

            if (right - left > minSize) {
                if (--cnt[s[left] - 'a'] == 0) {
                    --unique;
                }
                ++left;
            }

            if (right - left == minSize && unique <= maxLetters) {
                res = max(res, ++m[s.substr(left, minSize)]);
            }
        }

        return res;
    }
};

void testMaxFreq() {
    Solution solution;

    assert(solution.maxFreq("aababcaab", 2, 3, 4) == 2);
    assert(solution.maxFreq("aaaa", 1, 3, 3) == 2);
    assert(solution.maxFreq("aabcabcab", 2, 2, 3) == 3);
    assert(solution.maxFreq("abcde", 2, 3, 3) == 0);
}

int main() {
    testMaxFreq();

    return 0;
}