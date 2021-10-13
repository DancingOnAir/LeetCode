#include <string>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        vector<int> m;
        int numOfLetter = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == letter) {
                ++numOfLetter;
            }

            m.push_back(numOfLetter);
        }
        reverse(m.begin(), m.end());

        stack<char> stk;
        stk.push('#');
        for (int i = 0; i < n; ++i) {
            while (stk.top() > s[i] && (stk.size() + n - i > k + 1) && (stk.top() != letter || repetition < m[i])) {
                char cur = stk.top();
                if (cur == letter) {
                    ++repetition;
                }
                stk.pop();
            }

            if (stk.size() < k + 1 && (stk.size() + repetition - (s[i] == letter) < k + 1)) {
                if (s[i] == letter) {
                    --repetition;
                }
                stk.push(s[i]);
            }
        }

        string res;
        while (k > 0) {
            res += stk.top();
            stk.pop();
            --k;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void testSmallestSubsequence() {
    Solution solution;
    assert(solution.smallestSubsequence("leet", 3, 'e', 1) == "eet");
    assert(solution.smallestSubsequence("leetcode", 4, 'e', 2) == "ecde");
    assert(solution.smallestSubsequence("bb", 2, 'b', 2) == "bb");
}

int main() {
    testSmallestSubsequence();

    return 0;
}