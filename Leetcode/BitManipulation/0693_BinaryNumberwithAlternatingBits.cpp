#include <iostream>
using namespace std;

class Solution {
public:
    // cancel bits
    bool hasAlternatingBits(int n) {
        n ^= (n >> 2);

        return !(n & (n - 1));
    }

    bool hasAlternatingBits2(int n) {
        if (!n)
            return false;

        int count = 0;
        bool res = true;
        while (n) {
            if (!count++) {
                if (n & 1) {
                    res = true;
                }
                else {
                    res = false;
                }
                n >>= 1;
                continue;
            }

            if (res == (n & 1))
                return false;

            res = !res;
            n >>= 1;
        }

        return true;
    }
};

void testHasAlternatingBits() {
    Solution solution;

    cout << (solution.hasAlternatingBits(5)? "True" : "False") << endl;
    cout << (solution.hasAlternatingBits(7)? "True" : "False") << endl;
    cout << (solution.hasAlternatingBits(11)? "True" : "False") << endl;
    cout << (solution.hasAlternatingBits(10)? "True" : "False") << endl;
}

int main() {
    testHasAlternatingBits();
    return 0;
}