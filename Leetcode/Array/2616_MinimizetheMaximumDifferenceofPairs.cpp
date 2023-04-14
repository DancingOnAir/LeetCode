#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (nums.empty())
            return -1;

        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int i = 1, k = 0;
            while (i < nums.size()) {
                if (nums[i] - nums[i - 1] <= mid) {
                    ++k;
                    ++i;
                }
                ++i;
            }

            if (k < p) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

void testMinimizeMax() {
    Solution solution;
    vector<int> nums1 {10,1,2,7,1,3};
    cout << solution.minimizeMax(nums1, 2) << endl;
    vector<int> nums2 {4,2,1,2};
    cout << solution.minimizeMax(nums2, 1) << endl;
}

int main() {
    testMinimizeMax();
    return 0;
}