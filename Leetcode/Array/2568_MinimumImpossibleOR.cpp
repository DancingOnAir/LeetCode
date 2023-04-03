#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < 32; ++i) {
            if (!s.count(1 << i)) {
                return 1 << i;
            }
        }

        return -1;
    }
};

void testMinImpossibleOR() {
    Solution solution;
    vector<int> nums1{2, 1};
    cout << solution.minImpossibleOR(nums1) << endl;
    vector<int> nums2{5, 3, 2};
    cout << solution.minImpossibleOR(nums2) << endl;
}

int main() {
    testMinImpossibleOR();
    return 0;
}