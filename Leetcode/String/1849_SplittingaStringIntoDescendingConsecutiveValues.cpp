#include <string>

using namespace std;
class Solution {
public:
    bool dfs(string s, unsigned long long pre) {
        if (pre != -1 && stoull(s) == pre - 1)
            return true;

        for (int i = 1; i < s.size(); ++i) {
            unsigned long long cur = stoull(s.substr(0, i));
            if (pre == -1 || cur == pre - 1) {
                if (dfs(s.substr(i), cur)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool splitString(string s) {
        return dfs(s, -1);
    }
};

void testSplitString() {
    Solution solution;
    assert(!solution.splitString("1234"));
    assert(solution.splitString("050043"));
    assert(!solution.splitString("9080701"));
    assert(solution.splitString("10009998"));
    assert(!solution.splitString("94650723337775781477"));
}

int main() {
    testSplitString();

    return 0;
}