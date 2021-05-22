#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26);
        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        int res = 0;
        for (int i : freq) {
            if (i > 0)
                res += i;
        }
        return res;
    }
};

void testMinSteps() {
    Solution solution;
    assert(solution.minSteps("bab", "aba") == 1);
    assert(solution.minSteps("leetcode", "practice") == 5);
    assert(solution.minSteps("anagram", "mangaar") == 0);
    assert(solution.minSteps("xxyyzz", "xxyyzz") == 0);
    assert(solution.minSteps("friend", "family") == 4);
}

int main() {
    testMinSteps();

    return 0;
}