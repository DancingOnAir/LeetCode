#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        auto n = nums.size();
        vector<int> res(n);
        int mx = (1 << maximumBit) - 1;
        for (int i = 0; i < n; ++i) {
            res[n - i - 1] = mx ^= nums[i];
        }
        
        return res;
    }
};

void testGetMaximumXor() {
    Solution solution;
    vector<int> nums1 {0,1,1,3};
    auto res1 = solution.getMaximumXor(nums1, 2);
    for (int x : res1) {
        cout << x << ", ";
    }
    cout << endl;

    vector<int> nums2 {2,3,4,7};
    auto res2 = solution.getMaximumXor(nums2, 3);
    for (int x : res2) {
        cout << x << ", ";
    }
    cout << endl;
}


int main() {
    testGetMaximumXor();
    return 0;
}