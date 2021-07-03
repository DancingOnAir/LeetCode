#include <string>

using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        int resStartWithZero = 0, resStartWithOne = 0, res = 0x3f3f3f3f;
        for (int i = 0; i < 2 * n; ++i) {
            s[i] -= '0';
            if (i % 2 != s[i])
                ++resStartWithZero;
            if ((i + 1) % 2 != s[i])
                ++resStartWithOne;

            if (i >= n) {
                if ((i - n) % 2 != s[i - n])
                    --resStartWithZero;
                if ((i - n + 1) % 2 != s[i - n])
                    --resStartWithOne;
            }

            if (i >= n - 1)
                res = min({res, resStartWithZero, resStartWithOne});
        }

        return res;
    }
};

void testMinFlips() {
    Solution solution;
    assert(solution.minFlips("111000") == 2);
    assert(solution.minFlips("010") == 0);
    assert(solution.minFlips("1110") == 1);
}

int main() {
    testMinFlips();

    return 0;
}