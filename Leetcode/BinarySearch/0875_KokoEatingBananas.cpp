#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right - left) / 2, total = 0;
            for (int x : piles) {
                total += (mid + x - 1) / mid;
            }

            if (total > h) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

void testMinEatingSpeed() {
    Solution solution;
    vector<int> piles1 {3,6,7,11};
    cout << solution.minEatingSpeed(piles1, 8) << endl;
    vector<int> piles2 {30,11,23,4,20};
    cout << solution.minEatingSpeed(piles2, 5) << endl;
    cout << solution.minEatingSpeed(piles2, 6) << endl;
}

int main() {
    testMinEatingSpeed();
    return 0;
}