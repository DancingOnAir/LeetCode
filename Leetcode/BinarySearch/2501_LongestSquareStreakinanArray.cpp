#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> seen;
        int res = -1;
        for (int num : nums) {
            if (seen.count(num)) {
                continue;
            }

            long long x = num;
            long long cur = 1;
            while (binary_search(nums.begin(), nums.end(), x * x)) {
                ++cur;
                x *= x;
            }

            if (cur > 1 && cur > res) {
                res = cur;
            }
        }
        return res;
    }
};

void testLongestSquareStreak() {
    Solution solution;
    vector<int> nums1 {4,3,6,16,8,2};
    cout << solution.longestSquareStreak(nums1) << endl;
    vector<int> nums2 {2,3,5,6,7};
    cout << solution.longestSquareStreak(nums2) << endl;
}

int main() {
    testLongestSquareStreak();
    return 0;
}