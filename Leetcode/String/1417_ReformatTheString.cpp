#include <string>

using namespace std;
class Solution {
public:
    string reformat(string s) {
        string digits = "";
        string alphabets = "";

        for (char c : s) {
            if (isalpha(c)) {
                alphabets += c;
            }
            else {
                digits += c;
            }
        }

        if (abs((int)digits.size() - (int)alphabets.size()) > 1) {
            return "";
        }

        if (digits.size() < alphabets.size()) {
            swap(digits, alphabets);
        }

        string res = "";
        int i = 0;
        while (i < min(digits.size(), alphabets.size())) {
            res.push_back(digits[i]);
            res.push_back(alphabets[i++]);
        }

        if (i < max(digits.size(), alphabets.size())) {
            res.push_back(digits[i]);
        }

        return res;
    }
};

void testReformat() {
    Solution solution;

    assert(solution.reformat("a0b1c2") == "0a1b2c");
    assert(solution.reformat("leetcode") == "");
    assert(solution.reformat("1229857369") == "");
    assert(solution.reformat("covid2019") == "c2o0v1i9d");
    assert(solution.reformat("ab123") == "1a2b3");
}

int main() {
    testReformat();

    return 0;
}