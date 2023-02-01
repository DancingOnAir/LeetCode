#include <vector>
#include <iostream>

using std::vector, std::cout, std::endl, std::min;
class Solution {
public:
    int dp[16384] = {[0 ... 16383] = INT_MAX};
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2, int mask = 0, int i = 0) {
        if (i >= nums1.size()) {
            return 0;
        }
        
        for (int j = 0; j < nums2.size(); ++j) {
            if ((mask & (1 << j)) == 0) {
                dp[mask] = min(dp[mask], (nums1[i] ^ nums2[j])) + minimumXORSum(nums1, nums2, mask & (1 << j), i + 1);
            }
        }

        return dp[mask];
    }
};

void testMinimumXORSum() {
    Solution solution;

    vector<int> nums1 {1, 2};
    vector<int> nums2 {2, 3};
    cout << solution.minimumXORSum(nums1, nums2) << endl;
}

int main() {
    testMinimumXORSum();
    return 0;
}