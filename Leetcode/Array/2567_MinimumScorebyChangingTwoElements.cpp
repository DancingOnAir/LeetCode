#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        auto n = nums.size();
        sort(nums.begin(), nums.end());
        return min({nums[n - 1] - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0]});
    }
};

void testMinimizeSum() {
    Solution solution;
    vector<int> nums1 {1, 4, 3};
    cout << solution.minimizeSum(nums1) << endl;
    vector<int> nums2 {1, 4, 7, 8, 5};
    cout << solution.minimizeSum(nums2) << endl;
}

int main() {
    testMinimizeSum();
    return 0;
}