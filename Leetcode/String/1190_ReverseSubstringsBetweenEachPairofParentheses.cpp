#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> opened;
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                opened.push_back(res.size());
            }
            else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                reverse(res.begin() + j, res.end());
            }
            else {
                res.push_back(s[i]);
            }
        }

        return res;
    }

    // stack
    string reverseParentheses1(string s) {
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