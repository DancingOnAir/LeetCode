#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int high = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            res += 1LL * (high - low);
        }
        return res;
    }
};

void testCountFairPairs() {
    Solution solution;
    vector<int> nums1 {0,1,7,4,4,5};
    cout << solution.countFairPairs(nums1, 3, 6) << endl;
}

int main() {
    testCountFairPairs();
    return 0;
}