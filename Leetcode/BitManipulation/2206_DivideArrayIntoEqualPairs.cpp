#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& x : nums) {
            m[x] += 1;
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2 == 1) {
                return false;
            }
        }
        return true;
    }
};


void testDivideArray() {
    Solution solution;
    vector<int> nums1 {3, 2, 3, 2, 2, 2};
    cout << solution.divideArray(nums1) << endl;
    vector<int> nums2 {1, 2, 3, 4};
    cout << solution.divideArray(nums2) << endl;
}


int main() {
    testDivideArray();
    return 0;
}