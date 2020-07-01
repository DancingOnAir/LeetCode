#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int res = 0, minInterval = INT_MAX, maxInterval = INT_MIN, total = 0;

        for (int i = 0; i < n - 1; ++i) {
            int l = nums[i], r = nums[i + 1];
            total += abs(l - r);
            
            res = max(res, abs(nums[0] - r) - abs(l - r));
            res = max(res, abs(nums[n - 1] - l) - abs(l - r));

            minInterval = min(minInterval, max(l, r));
            maxInterval = max(maxInterval, min(l, r));
        }

        return total + max(res, (maxInterval - minInterval) * 2);
    }

    int maxValueAfterReverse1(vector<int>& nums) {
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

        int maxDiff = 0, curDiff = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (0 == i && n - 1 == j) {
                    continue;
                }
                else if (0 == i) {
                    curDiff = abs(nums[j + 1] - nums[i]) - values[j];
                }
                else if (n - 1 == j) {
                    curDiff = abs(nums[j] - nums[i - 1]) - values[i - 1];
                }
                else {
                    curDiff = abs(nums[j] - nums[i - 1]) + abs(nums[j + 1] - nums[i]) - values[i - 1] - values[j];
                }

                maxDiff = max(maxDiff, curDiff);
            }
        }

        return res + maxDiff;
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