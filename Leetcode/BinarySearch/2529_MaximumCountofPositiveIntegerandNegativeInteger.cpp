#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto low = lower_bound(nums.begin(), nums.end(), 0);
        auto high = upper_bound(nums.begin(), nums.end(), 0);
        return max(nums.end() - high, low - nums.begin());
    }
};

void testMaximumCount() {
    Solution solution;
    vector<int> nums1 {-2,-1,-1,1,2,3};
    cout << solution.maximumCount(nums1) << endl;
    vector<int> nums2 {-3,-2,-1,0,0,1,2};
    cout << solution.maximumCount(nums2) << endl;
    vector<int> nums3 {5,20,66,1314};
    cout << solution.maximumCount(nums3) << endl;
}

int main() {
    testMaximumCount();
    return 0;
}