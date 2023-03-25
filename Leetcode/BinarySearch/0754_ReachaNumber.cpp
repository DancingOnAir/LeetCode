#include <iostream>
#include <cmath>

using namespace std;
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = ceil((sqrt(8L * target + 1) - 1) / 2);
        return (n * (n + 1) / 2 - target) % 2 == 0 ? n : n + 1 + n % 2;
    }
};

void testReachNumber() {
    Solution solution;
    cout << solution.reachNumber(2) << endl;
    cout << solution.reachNumber(3) << endl;
}

int main() {
    testReachNumber();
    return 0;
}
