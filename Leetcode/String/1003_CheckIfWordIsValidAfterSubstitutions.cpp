#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    // two pointers solution
    bool isValid(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'c' && j > 1 && s[j - 1] == 'b' && s[j - 2] == 'a')
                j -= 2;
            else
                s[j++] = s[i];
        }

        return j == 0;
    }

    // stack solution
    bool isValid1(string s) {
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