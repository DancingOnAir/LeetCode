#include <string>

using namespace std;
class Solution {
public:
    int minOperations(string s) {
        unsigned long diff = 0;
        for (auto i = 0; i < s.size(); ++i) {
            printf("%d", (i & 1));
            if ((s[i] - '0') != (i & 1))
                ++diff;
        }

        return min(diff, s.size() - diff);
    }
};

void testMinOperations() {
    Solution solution;

    assert(solution.minOperations("0100") == 1);
    assert(solution.minOperations("10") == 0);
    assert(solution.minOperations("1111") == 2);
}

int main() {
    testMinOperations();

    return 0;
}