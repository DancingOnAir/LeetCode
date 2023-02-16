#include <iostream>

using namespace std;
// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
    return version >= 4;
}

class Solution {
public:
    // left bound
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

void testFirstBadVersion() {
    Solution solution;
    cout << solution.firstBadVersion(5) << endl;
}

int main() {
    testFirstBadVersion();
    return 0;
}