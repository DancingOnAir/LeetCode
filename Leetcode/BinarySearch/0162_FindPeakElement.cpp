#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/find-peak-element/solutions/1334653/python-binary-search-solution-explained/?orderBy=most_votes
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

void testFindPeakElement() {
    Solution solution;
    vector<int> nums1 {1, 2, 3, 1};
    cout << solution.findPeakElement(nums1) << endl;
    vector<int> nums2 {1, 2, 1, 3, 5, 6, 4};
    cout << solution.findPeakElement(nums2) << endl;
}

int main() {
    testFindPeakElement();
    return 0;
}
