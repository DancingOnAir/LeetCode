#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;

        vector<int> values;
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            values.emplace_back(abs(nums[i + 1] - nums[i]));
            res += values.back();
        }

        if (n < 3)
            return res;

        int diff = 0;
        // for (int i = 0; i < n - 1; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         diff = max(diff, )
        //     }
        // }
        return res;
    }
};

void testMaxValueAfterReverse() {
    Solution solution;

    vector<int> nums1 {2, 3, 1, 5, 4};
    cout << solution.maxValueAfterReverse(nums1) << endl;

    vector<int> nums2 {2, 4, 9, 24, 2, 1, 10};
    cout << solution.maxValueAfterReverse(nums2) << endl;
}

int main() {
    testMaxValueAfterReverse();

    return 0;
}