#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int res = 0;
        for (int i = 0, cnt = 0; i <= text.size(); ++i) {
            if (i == text.size() || text[i] == ' ') {
                res += cnt == 0;
                cnt = 0;
            }
            else if (cnt == 0) {
                cnt += broken.count(text[i]);
            }
        }
        return res;
    }
};

void testCanBeTypedWords() {
    Solution solution;

    assert(solution.canBeTypedWords("hello world", "ad") == 1);
    assert(solution.canBeTypedWords("leet code", "lt") == 1);
    assert(solution.canBeTypedWords("leet code", "e") == 0);
}

int main() {
    testCanBeTypedWords();

    return 0;
}