#include <string>

using namespace std;
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto op = [](string& s) {
            for (auto& c : s) {
                c -= 49;
            }
            return stoi(s);
        };

        return op(firstWord) + op(secondWord) == op(targetWord);
    }
};

void testIsSumEqual() {
    Solution solution;

    assert(solution.isSumEqual("acb", "cba", "cdb"));
    assert(!solution.isSumEqual("aaa", "a", "aab"));
    assert(solution.isSumEqual("aaa", "a", "aaaa"));
}

int main() {
    testIsSumEqual();

    return 0;
}