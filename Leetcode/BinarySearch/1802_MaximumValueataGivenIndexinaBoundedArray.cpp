#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    int calculateSum(int n, int index, int a) {
        int b = max(0, a - index);
        long long res = (long long)(a + b) * (a - b + 1) / 2;
        b = max(0, a - ((n - 1) - index));
        res += (long long)(a + b) * (a - b + 1) / 2;
        return res - a;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cur  = calculateSum(n, index, mid);
            if (cur > maxSum) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

void testMaxValue() {
    Solution solution;
    cout << solution.maxValue(4, 2, 6) << endl;
    cout << solution.maxValue(6, 1, 10) << endl;
}

int main() {
    testMaxValue();
    return 0;
}