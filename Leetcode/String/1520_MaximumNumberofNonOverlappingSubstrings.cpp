#include <vector>
#include <string>
#include <numeric>

using namespace std;
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26, INT_MAX), right(26, INT_MIN), skip(26);

        for (int i = 0; i < s.size(); ++i) {
            left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = i;
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = left[i]; j <= right[i]; ++j) {
                if (left[s[j] - 'a'] < left[i]) {
                    skip[i] = 1;
                }
                else {
                    right[i] = max(right[i], right[s[j] - 'a']);
                }
            }
        }

        vector<string> res;
        for (int i = s.size() - 1, cur = INT_MAX; i >= 0; --i) {
            if (i == left[s[i] - 'a'] && right[s[i] - 'a'] < cur && !skip[s[i] - 'a']) {
                res.push_back(s.substr((cur = i), right[s[i] - 'a'] - i + 1));
            }
        }

        return res;
    }
};

void testMaxNumOfSubstrings() {
    Solution solution;

    assert(solution.maxNumOfSubstrings("adefaddaccc") == vector<string>({"e", "f", "ccc"}));
    assert(solution.maxNumOfSubstrings("abbaccd") == vector<string>({"d", "bb", "cc"}));
}

int main() {
    testMaxNumOfSubstrings();

    return 0;
}