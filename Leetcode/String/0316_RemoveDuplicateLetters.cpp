#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<int, int> memo;
        for (int i = 0; i < s.size(); ++i) {
            memo[s[i] - 'a'] = i;
        }

        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (res.find(s[i]) != string::npos) {
                continue;
            }

            while (!res.empty() && res.back() > s[i] && memo[res.back() - 'a'] > i) {
                res.pop_back();
            }

            res.push_back(s[i]);
        }

        return res;
    }
};

void testRemoveDuplicateLetters() {
    Solution solution;

    assert(solution.removeDuplicateLetters("bcabc") == "abc");
    assert(solution.removeDuplicateLetters("cbacdcbc") == "acdb");
}

int main() {
    testRemoveDuplicateLetters();

    return 0;
}