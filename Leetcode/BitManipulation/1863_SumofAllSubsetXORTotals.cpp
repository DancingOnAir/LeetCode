#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (auto i = 1; i < (1 << nums.size()); ++i) {
            int total = 0;
            for (auto j = 0; j < nums.size(); ++j) {
                if (i & (1 << j)) {
                    total ^= nums[j];
                }
            }

            res += total;
        }
        return res;
    }
};


void testSubsetXORSum() {
    Solution solution;
    vector<int> nums1 {1, 3};
    cout << solution.subsetXORSum(nums1) << endl;
    vector<int> nums2 {5, 1, 6};
    cout << solution.subsetXORSum(nums2) << endl;
    vector<int> nums3 {3, 4, 5, 6, 7, 8};
    cout << solution.subsetXORSum(nums3) << endl;
}


int main() {
    testSubsetXORSum();
    return 0;
}