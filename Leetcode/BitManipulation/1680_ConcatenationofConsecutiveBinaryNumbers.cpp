#include <iostream>
#include <cmath>

using std::cout, std::endl;
class Solution {
public:
    int numOfBits(int x) {
        return log2(x) + 1;
    }

    int concatenatedBinary(int n) {
        long res = 0, MOD = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            int len = 32 - __builtin_clz(i);
            res = ((res << len) % MOD + i) % MOD;
        }

        return res;
    }
};

void testConcatenatedBinary() {
    Solution solution;
    cout << solution.concatenatedBinary(1) << endl;
    cout << solution.concatenatedBinary(3) << endl;
    cout << solution.concatenatedBinary(12) << endl;
}

int main() {
    testConcatenatedBinary();
    return 0;
}