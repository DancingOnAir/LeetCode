#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right -left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

void testSearch() {
    Solution solution;
    vector<int> nums {-1,0,3,5,9,12};
    cout << solution.search(nums, 9) << endl;
    cout << solution.search(nums, 2) << endl;
}

int main() {
    testSearch();
    return 0;
}