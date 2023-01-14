#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};


void testMinBitFlips() {
    Solution solution;
    assert(solution.minBitFlips(10, 7) == 3);
    cout << solution.minBitFlips(3, 4) << endl;
    assert(solution.minBitFlips(10, 7) == 3);
}


int main() {
    testMinBitFlips();
    return 0;
}