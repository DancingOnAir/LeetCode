#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:

    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> f((1 << (numSlots * 2)));
        int res = 0;
        for (int i = 0; i < f.size(); ++i) {
            int c = __builtin_popcount(i);
            if (c >= nums.size())
                continue;

            for (int j = 0; j < numSlots * 2; ++j) {
                if ((i & (1 << j)) == 0) {
                    int s = i | (1 << j);
                    f[s] = max(f[s], f[i] + (nums[c] & (j / 2 + 1)));
                    res = max(res, f[s]);
                } 
            }
        }

        return res;
    }
};

void testMaximumANDSum() {
    Solution solution;
    vector<int> nums1 {1, 2, 3, 4, 5, 6};
    cout << solution.maximumANDSum(nums1, 3) << endl;
    vector<int> nums2 {1, 3, 10, 4, 7, 1};
    cout << solution.maximumANDSum(nums2, 9) << endl;
}

int main() {
    testMaximumANDSum();
    return 0;
}