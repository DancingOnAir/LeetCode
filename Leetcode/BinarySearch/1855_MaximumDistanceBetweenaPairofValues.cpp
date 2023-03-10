#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        reverse(nums2.begin(), nums2.end());
        int res = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int j = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            j = nums2.size() - 1 - j;
            if (j >= i) {
                res = max(res, j - i);
            }
        }

        return res;
    }
};

void testMaxDistance() {
    Solution solution;
    vector<int> nums1 {55,30,5,4,2};
    vector<int> nums2 {100,20,10,10,5};
    cout << solution.maxDistance(nums1, nums2) << endl;
}

int main() {
    testMaxDistance();
    return 0;
}