#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int h : houses) {
            auto iter = lower_bound(heaters.begin(), heaters.end(), h);
            int cur = INT_MAX;
            if (iter != heaters.end()) {
                cur = *iter - h;
            }

            if (iter != heaters.begin()) {
                cur = min(cur, h - *(iter - 1));
            }

            res = max(res, cur);
        }

        return res;
    }
};

void testFindRadius() {
    Solution solution;

    vector<int> houses1 {1, 2, 3};
    vector<int> heaters1 {2};
    cout << solution.findRadius(houses1, heaters1) << endl;

    vector<int> houses2 {1, 2, 3, 4};
    vector<int> heaters2 {1, 4};
    cout << solution.findRadius(houses2, heaters2) << endl;
}

int main() {
    testFindRadius();
    return 0;
}
