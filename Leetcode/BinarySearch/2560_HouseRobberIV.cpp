#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 1, right = 1e9;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int take = 0, last = 0;
            for (int x : nums) {
                if (last) {
                    last = 0;
                    continue;
                }

                if (x <= mid) {
                    ++take;
                    last = 1;
                }

            }

            if (take >= k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

void testMinCapability() {
    Solution solution;
    vector<int> nums1 {2,3,5,9};
    cout << solution.minCapability(nums1, 2) << endl;
    vector<int> nums2 {2,7,9,3,1};
    cout << solution.minCapability(nums2, 2) << endl;
}

int main() {
    testMinCapability();
    return 0;
}