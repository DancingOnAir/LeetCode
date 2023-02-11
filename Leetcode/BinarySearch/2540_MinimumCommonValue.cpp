#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }

            i += nums1[i] < nums2[j];
            j += nums1[i] > nums2[j];
        }

        return -1;
    }
};


void testGetCommon() {
    Solution solution;

    vector<int> nums1 {1, 2, 3};
    vector<int> nums2 {2, 4};
    cout << solution.getCommon(nums1, nums2) << endl;
}

int main() {
    testGetCommon();
    return 0;
}