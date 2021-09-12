#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        string stk;
        for (char c : s) {
            if (c == ')') {
                string cur;
                while (stk.back() != '(') {
                    cur.push_back(stk.back());
                    stk.pop_back();
                }

                stk.pop_back();
                stk.append(cur);
            }
            else {
                stk.push_back(c);
            }
        }

        return stk;
    }
};

void testReverseParentheses() {
    Solution solution;
    assert(solution.reverseParentheses("(abcd)") == "dcba");
    assert(solution.reverseParentheses("(u(love)i)") == "iloveu");
    assert(solution.reverseParentheses("(ed(et(oc))el)") == "leetcode");
    assert(solution.reverseParentheses("a(bcdefghijkl(mno)p)q") == "apmnolkjihgfedcbq");
}

int main() {
    testReverseParentheses();

    return 0;
}