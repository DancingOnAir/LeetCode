#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        vector<int> dp(1 << nums.size());
        dp[0] = 1;
        for (int x: nums) {
            for (int i = mx; i >= 0; --i) {
                dp[x | i] += dp[i];
            }

            mx |= x;
        }

        return dp[mx];
    }
};

void testCountMaxOrSubsets() {
    Solution solution;
    vector<int> nums1 {3, 1};
    cout << solution.countMaxOrSubsets(nums1) << endl;
    vector<int> nums2 {2, 2, 2};
    cout << solution.countMaxOrSubsets(nums2) << endl;
    vector<int> nums3 {3, 2, 1, 5};
    cout << solution.countMaxOrSubsets(nums3) << endl;
}

int main() {
    testCountMaxOrSubsets();
    return 0;
}