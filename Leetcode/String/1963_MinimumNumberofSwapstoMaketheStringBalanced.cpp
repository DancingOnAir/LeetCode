#include <string>

using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int open_bracket = 0;
        for (char& c : s) {
            if (open_bracket > 0 && c == ']')
                --open_bracket;
            else if (c == '[')
                ++open_bracket;
        }

        return (open_bracket + 1) / 2;
    }
};

void testMinSwaps() {
    Solution solution;

    assert(solution.minSwaps("][][") == 1);
    assert(solution.minSwaps("]]][[[") == 2);
    assert(solution.minSwaps("[]") == 0);
}

int main() {
    testMinSwaps();

    return 0;
}