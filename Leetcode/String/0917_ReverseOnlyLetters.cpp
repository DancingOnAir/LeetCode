#include <string>

using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalpha(s[i])) {
                ++i;
            }
            else if (!isalpha(s[j])) {
                --j;
            }
            else {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }

        return s;
    }
};

void testReverseOnlyLetters() {
    Solution solution;

    assert(solution.reverseOnlyLetters("ab-cd") == "dc-ba");
    assert(solution.reverseOnlyLetters("a-bC-dEf-ghIj") == "j-Ih-gfE-dCba");
    assert(solution.reverseOnlyLetters("Test1ng-Leet=code-Q!") == "Qedo1ct-eeLg=ntse-T!");
}

int main() {
    testReverseOnlyLetters();

    return 0;
}