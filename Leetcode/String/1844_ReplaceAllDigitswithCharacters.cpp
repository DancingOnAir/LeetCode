#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = s[i - 1] + s[i] - '0';
        }

        return s;
    }
};

void testReplaceDigits() {
    Solution solution;
    assert(solution.replaceDigits("a1c1e1") == "abcdef");
    assert(solution.replaceDigits("a1b2c3d4e") == "abbdcfdhe");
}

int main() {
    testReplaceDigits();

    return 0;
}