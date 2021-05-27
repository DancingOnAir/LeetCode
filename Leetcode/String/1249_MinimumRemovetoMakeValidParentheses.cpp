#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.emplace(i);
            }
            else if(s[i] == ')') {
                if (!stk.empty())
                    stk.pop();
                else
                    s[i] = '*';
            }
        }

        while (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};

void testMinRemoveToMakeValid() {
    Solution solution;

    assert(solution.minRemoveToMakeValid("lee(t(c)o)de)") == "lee(t(c)o)de");
    assert(solution.minRemoveToMakeValid("a)b(c)d") == "ab(c)d");
    assert(solution.minRemoveToMakeValid("))((") == "");
    assert(solution.minRemoveToMakeValid("(a(b(c)d)") == "a(b(c)d)");
}

int main() {
    testMinRemoveToMakeValid();

    return 0;
}