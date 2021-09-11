#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3)
            return s;

        string res;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == res.back()) {
                ++cnt;
            }
            else {
                cnt = 1;
            }

            if (cnt < 3)
                res.push_back(s[i]);
        }

        return res;
    }
};

void testMakeFancyString() {
    Solution solution;

    assert(solution.makeFancyString("leeetcode") == "leetcode");
    assert(solution.makeFancyString("aaabaaaa") == "aabaa");
    assert(solution.makeFancyString("aab") == "aab");
}

int main() {
    testMakeFancyString();

    return 0;
}