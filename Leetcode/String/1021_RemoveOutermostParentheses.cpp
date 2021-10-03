#include <string>

using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string res;
        for(char c : s) {
            if (c == '(' && cnt++ > 0) {
                res += c;
            }
            else if (c == ')' && --cnt > 0) {
                res += c;
            }
        }

        return res;
    }
};

void testRemoveOuterParentheses() {
    Solution solution;
    assert(solution.removeOuterParentheses("(()())(())") == "()()()");
    assert(solution.removeOuterParentheses("(()())(())(()(()))") == "()()()()(())");
    assert(solution.removeOuterParentheses("()()") == "");
}

int main() {
    testRemoveOuterParentheses();

    return 0;
}