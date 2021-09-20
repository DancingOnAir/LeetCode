#include <string>

using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto idx = word.find(ch);
        if (idx != string::npos)
            reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};

void testReversePrefix() {
    Solution solution;

    assert(solution.reversePrefix("abcdefd", 'd') == "dcbaefd");
    assert(solution.reversePrefix("xyxzxe", 'z') == "zxyxxe");
    assert(solution.reversePrefix("abcd", 'z') == "abcd");
}

int main() {
    testReversePrefix();

    return 0;
}