#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = 1L * ranks[0] * cars * cars;
        while (left <= right) {
            long long mid = left + (right - left) / 2, total = 0;
            for (int x : ranks) {
                total += (long long)sqrt(mid / x);
            }

            if (total < cars) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

void testRepairCars() {
    Solution solution;
    vector<int> ranks1 {4, 2, 3, 1};
    cout << solution.repairCars(ranks1, 10) << endl;
    vector<int> ranks2 {5, 1, 8};
    cout << solution.repairCars(ranks2, 6) << endl;
}

int main() {
    testRepairCars();
    return 0;
}