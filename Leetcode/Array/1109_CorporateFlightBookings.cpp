#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for (auto& booking : bookings) {
            for (int i = booking[0] - 1; i < booking[1]; ++i) {
                res[i] += booking[2];
            }
        }

        return res;
    }
};

void printRes(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testCorpFlightBookings() {
    Solution solution;

    vector<vector<int>> bookings1 {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    auto res1 = solution.corpFlightBookings(bookings1, 5);
    printRes(res1);
}

int main() {
    testCorpFlightBookings();

    return 0;
}