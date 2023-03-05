#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/solutions/1064548/java-c-python-binary-search/
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        while (left <= right) {
            int mid = left + (right - left) /2;
            int cnt = 0;
            for (int x : nums) {
                cnt += (x - 1) / mid;
            }

            if (cnt > maxOperations) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

void testMinimumSize() {
    Solution solution;
    vector<int> nums1 {9};
    cout << solution.minimumSize(nums1, 2) << endl;
    vector<int> nums2 {2,4,8,2};
    cout << solution.minimumSize(nums2, 4) << endl;
}

int main() {
    testMinimumSize();
    return 0;
}