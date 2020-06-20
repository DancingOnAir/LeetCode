#include <iostream>
#include <vector>

using namespace std;

static const auto fast = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1);
        for (auto& booking : bookings) {
            res[booking[0] - 1] += booking[2];
            res[booking[1]] -= booking[2];
        }
        
        for (int i = 1; i < n; ++i) {
            res[i] += res[i - 1];
        }

        res.pop_back();
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