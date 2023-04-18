#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int x : nums) {
            if (nums[i] < x) {
                ++i;
            }
        }

        return i;
    }
};

void testMaximizeGreatness() {
    Solution solution;
    vector<int> nums1 {1,3,5,2,1,3,1};
    cout << solution.maximizeGreatness(nums1) << endl;
    vector<int> nums2 {1, 2, 3, 4};
    cout << solution.maximizeGreatness(nums2) << endl;
}

int main() {
    testMaximizeGreatness();
    return 0;
}
