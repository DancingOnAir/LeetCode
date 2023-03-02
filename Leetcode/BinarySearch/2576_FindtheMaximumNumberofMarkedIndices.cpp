#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        auto iter = nums.begin();
        
        for (int i = 0; i < n / 2; ++i) {
            ++iter;
            iter = lower_bound(iter, nums.end(), nums[i] * 2);
            if (iter == nums.end()) {
                break;
            }
            res += 2;
        }

        return res;
    }
};

void testMaxNumOfMarkedIndices() {
    Solution solution;
    vector<int> nums1 {3,5,2,4};
    cout << solution.maxNumOfMarkedIndices(nums1) << endl;
    vector<int> nums2 {9,2,5,4};
    cout << solution.maxNumOfMarkedIndices(nums2) << endl;
    vector<int> nums3 {7,6,8};
    cout << solution.maxNumOfMarkedIndices(nums3) << endl;
}

int main() {
    testMaxNumOfMarkedIndices();
    return 0;
}