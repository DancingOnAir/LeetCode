#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char& c : s) {
            if (c == 'c') {
                if (stk.empty() || stk.top() != 'b')
                    return false;
                stk.pop();

                if (stk.empty() || stk.top() != 'a')
                    return false;
                stk.pop();
            }
            else {
                stk.emplace(c);
            }
        }

        return stk.empty();
    }
};

void testIsValid() {
    Solution solution;

    assert(solution.isValid("aabcbc"));
    assert(solution.isValid("abcabcababcc"));
    assert(!solution.isValid("abccba"));
    assert(!solution.isValid("cababc"));
}

int main() {
    testIsValid();

    return 0;
}