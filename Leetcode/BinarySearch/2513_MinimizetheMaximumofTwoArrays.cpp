#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long left = 1, right = (uniqueCnt1 + uniqueCnt2) * 2 - 1;
        long l = lcm(divisor1, divisor2);
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (uniqueCnt1 <= mid - mid / divisor1 && uniqueCnt2 <= mid - mid / divisor2 && uniqueCnt1 + uniqueCnt2 <= mid - mid / l) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

void testMinimizeSet() {
    Solution solution;
    cout << solution.minimizeSet(2, 7, 1, 3) << endl;
    cout << solution.minimizeSet(3, 5, 2, 1) << endl;
    cout << solution.minimizeSet(2, 4, 8, 2) << endl;
}

int main() {
    testMinimizeSet();
    return 0;
}