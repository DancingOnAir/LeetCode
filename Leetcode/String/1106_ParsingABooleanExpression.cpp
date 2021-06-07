#include <string>
#include <stack>
#include <set>

using namespace std;
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char c : expression) {
            if (c == ')') {
                set<char> s;
                while (stk.top() != '(') {
                    s.emplace(stk.top());
                    stk.pop();
                }

                stk.pop();
                auto op = stk.top();
                stk.pop();

                if (op == '!') {
                    stk.emplace(s.find('t') == s.end() ? 't' : 'f');
                }
                else if (op == '|') {
                    stk.emplace(s.find('t') == s.end() ? 'f' : 't');
                }
                else {
                    stk.emplace(s.find('f') == s.end() ? 't' : 'f');
                }
            }
            else if (c != ',') {
                stk.emplace(c);
            }
        }

        return stk.top() == 't';
     }
};

void testParseBoolExpr() {
    Solution solution;

    assert(solution.parseBoolExpr("!(f)"));
    assert(solution.parseBoolExpr("|(f,t)"));
    assert(!solution.parseBoolExpr("&(t,f)"));
    assert(!solution.parseBoolExpr("|(&(t,f,t),!(t))"));
}

int main() {
    testParseBoolExpr();

    return 0;
}