#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;
class Solution {
public:
    bool possible(ll k, vector<int>& time, ll totalTrips) {
        ll res = 0;
        for (int t : time) {
            res += k / t;
        }
        return res >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll left = 1, right = (ll)totalTrips * (*min_element(time.begin(), time.end()));
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (possible(mid, time, totalTrips)) {
                right = mid  -1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

void testMinimumTime() {
    Solution solution;
    vector<int> time3 {66};
    cout << solution.minimumTime(time3, 8295) << endl;
    vector<int> time1 {1, 2, 3};
    cout << solution.minimumTime(time1, 5) << endl;
    vector<int> time2 {2};
    cout << solution.minimumTime(time2, 1) << endl;
}

int main() {
    testMinimumTime();
    return 0;
}
