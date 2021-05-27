#include <string>

using namespace std;
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x')
                    xy += 1;
                else
                    yx += 1;
            }
        }

        if ((xy + yx) & 1)
            return -1;
        return xy / 2 + (xy & 1) + yx / 2 + (yx & 1);
    }
};

void testMinimumSwap() {
    Solution solution;

    assert(solution.minimumSwap("xx", "yy") == 1);
    assert(solution.minimumSwap("xy", "yx") == 2);
    assert(solution.minimumSwap("xx", "xy") == -1);
    assert(solution.minimumSwap("xxyyxyxyxx", "xyyxyxxxyx") == 4);
}

int main() {
    testMinimumSwap();

    return 0;
}