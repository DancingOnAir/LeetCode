#include <string>

using namespace std;
class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int x = 0, y = 0;

        for (char c : target) {
            int x1 = (c - 'a') % 5;
            int y1 = (c - 'a') / 5;

            res += string(max(0, y - y1), 'U') + string(max(0, y1 - y), 'D') + string(max(0, x - x1), 'L') + string(max(0, x1 - x), 'R') + '!';
            x = x1;
            y = y1;
        }

        return res;
    }
};

void testAlphabetBoardPath() {
    Solution solution;
    assert(solution.alphabetBoardPath("leet") == "DDR!UURRR!!DDD!");
    assert(solution.alphabetBoardPath("code") == "RR!DDRR!UUL!R!");
}

int main() {
    testAlphabetBoardPath();

    return 0;
}