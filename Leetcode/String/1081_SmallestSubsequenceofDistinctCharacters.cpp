#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26);
        vector<int> used(26);
        string res;

        for (char c : s)
            ++cnt[c - 'a'];

        for (char c : s) {
            --cnt[c - 'a'];
            if (used[c - 'a']++ > 0)
                continue;
            while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0) {
                used[res.back() - 'a'] = 0;
                res.pop_back();
            }

            res += c;
        }

        return res;
    }
};

void testSmallestSubsequence() {
    Solution solution;

    assert(solution.smallestSubsequence("bcabc") == "abc");
    assert(solution.smallestSubsequence("cbacdcbc") == "acdb");
}

int main() {
    testSmallestSubsequence();

    return 0;
}