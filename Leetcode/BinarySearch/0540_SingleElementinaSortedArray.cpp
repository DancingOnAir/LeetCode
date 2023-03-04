#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/single-element-in-a-sorted-array/solutions/1587257/c-easy-intuitive-solution-2-approaches-binary-search-tc-o-log-n-sc-o-1/
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 等价于 ( mid%2==0 && nums[ mid ] == nums[ mid + 1 ] ) || ( mid%2 == 1 && nums[ mid ] == nums[ mid - 1 ] )
            if (nums[mid] == nums[mid ^ 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};

void testSingleNonDuplicate() {
    Solution solution;
    vector<int> nums1 {1,1,2,3,3,4,4,8,8};
    cout << solution.singleNonDuplicate(nums1) << endl;
    vector<int> nums2 {3,3,7,7,10,11,11};
    cout << solution.singleNonDuplicate(nums2) << endl;
}

int main() {
    testSingleNonDuplicate();
    return 0;
}