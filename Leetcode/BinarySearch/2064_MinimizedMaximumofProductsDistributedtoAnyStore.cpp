#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cur = 0;
            for (int x : quantities) {
                cur += (x - 1) / mid + 1;
            }

            if (cur > n) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

void testMinimizedMaximum() {
    Solution solution;
    vector<int> quantities1 {11, 6};
    cout << solution.minimizedMaximum(6, quantities1) << endl;
    vector<int> quantities2 {15, 10, 10};
    cout << solution.minimizedMaximum(7, quantities2) << endl;
    vector<int> quantities3 {100000};
    cout << solution.minimizedMaximum(1, quantities3) << endl;
}

int main() {
    testMinimizedMaximum();
    return 0;
}