#include <string>

using namespace std;
class Solution {
private:
    string longestSubsequence;

public:
    bool isRepeatTimesEqualOrGreatThanK(string sub, string& s, int k) {
        if (sub.empty())
            return s.size();

        int idx = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (sub[idx] == s[i]) {
                ++idx;
                if (idx == (int)sub.size()) {
                    idx = 0;
                    ++cnt;
                }
            }
        }

        return cnt >= k;
    }

    void dfs(string sub, string& s, int k) {
        if (!isRepeatTimesEqualOrGreatThanK(sub, s, k)) {
            return;
        }

        if (sub.size() >= longestSubsequence.size() && sub > longestSubsequence) {
            longestSubsequence = sub;
        }
        
        for (char c = 'a'; c <= 'z'; ++c) {
            dfs(sub + c, s, k);
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        longestSubsequence = "";
        dfs("", s, k);
        return longestSubsequence;
    }
};

void testLongestSubsequenceRepeatedK() {
    Solution solution;

    assert(solution.longestSubsequenceRepeatedK("letsleetcode", 2) == "let");
    assert(solution.longestSubsequenceRepeatedK("bb", 2) == "b");
    assert(solution.longestSubsequenceRepeatedK("ab", 2) == "");
    assert(solution.longestSubsequenceRepeatedK("bbabbabbbbabaababab", 3) == "bbbb");
}

int main() {
    testLongestSubsequenceRepeatedK();

    return 0;
}