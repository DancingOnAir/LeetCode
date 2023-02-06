#include <iostream>

using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int equal = (a | b) ^ c;
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            int mask = 1 << i;
            if ((equal & mask) > 0) {
                if ((a & mask) == (b & mask) && (c & mask) == 0) {
                    res += 2;
                }
                else {
                    res += 1;
                }
            }
        }
        return res;
    }
};

void testMinFlips() {
    Solution solution;
    cout << solution.minFlips(2, 6, 5) << endl;
    cout << solution.minFlips(4, 2, 7) << endl;
    cout << solution.minFlips(1, 2, 3) << endl;
}

int main() {
    testMinFlips();
    return 0;
}