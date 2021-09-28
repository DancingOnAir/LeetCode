#include <string>
#include <map>
#include <algorithm>

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

    string longestSubsequenceRepeatedK1(string s, int k) {
        longestSubsequence = "";
        dfs("", s, k);
        return longestSubsequence;
    }


    string longestSubsequenceRepeatedK(string s, int k) {
        map<char, int> freq;
        for (char& c : s) {
            ++freq[c];
        }

        string cand;
        for (auto& it: freq) {
            for (int i = 0; i < it.second / k; ++i) {
                cand += it.first;
            }
        }

        string res;
        for (int i = cand.size(); i > 0; --i) {
            string temp(cand);
            do {
                string t = temp.substr(0, i);
                if (isRepeatTimesEqualOrGreatThanK(t, s, k)) {
                    res = max(res, t);
                }
            }
            while (next_permutation(temp.begin(), temp.end()));
            
            if (!res.empty())
                return res;
        }
        return res;
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