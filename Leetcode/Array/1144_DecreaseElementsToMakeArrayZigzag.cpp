#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;

        int left = 0, right = 0;
        vector<int> res(2);
        for (int i = 0; i < n; ++i) {
            left = i > 0 ? nums[i - 1] : 1001;
            right = i < n - 1 ? nums[i + 1] : 1001;
            
            res[i & 1] += max(0, nums[i] - min(left, right) + 1);
        }

        return min(res[0], res[1]);
    }

    int movesToMakeZigzag1(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        // for even
        int res1 = 0;
        // for odd
        int res2 = 0;
        vector<int> copy(nums);
        for (int i = 0; i < n - 1; ++i) {
            if (i & 1) {
                if (nums[i] >= nums[i + 1]) {
                    int temp = nums[i] - nums[i + 1] + 1;
                    res1 += temp;
                }
            }
            else {
                if (nums[i] <= nums[i + 1]) {
                    int temp = nums[i + 1] - nums[i] + 1;
                    res1 += temp;
                    nums[i + 1] -= temp;
                }
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (i & 1) {
                if (copy[i] <= copy[i + 1]) {
                    int temp = copy[i + 1] - copy[i] + 1;
                    res2 += temp;
                    copy[i + 1] -= temp;
                }
            }
            else {
                if (copy[i] >= copy[i + 1]) {
                    int temp = copy[i] - copy[i + 1] + 1;
                    res2 += temp;
                }
            }
        }

        return min(res1, res2);
    }
};

void testMovesToMakeZigzag() {
    Solution solution;

    vector<int> nums1 {1, 2, 3};
    cout << solution.movesToMakeZigzag(nums1) << endl;

    vector<int> nums2 {9, 6, 1, 6, 2};
    cout << solution.movesToMakeZigzag(nums2) << endl;

    vector<int> nums3 {2, 7, 10, 9, 8, 9};
    cout << solution.movesToMakeZigzag(nums3) << endl;
}

int main() {
    testMovesToMakeZigzag();

    return 0;
}