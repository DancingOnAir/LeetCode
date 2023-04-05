#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        for (int i = 0, j = nums.size() - 1; i <= j; ++i, --j) {
            if (i < j) {
                res += nums[i] * pow(10, (int)log10(nums[j]) + 1) + nums[j];
            }
            else {
                res += nums[i];
            }
        }
        return res;
    }

    long long findTheArrayConcVal1(vector<int>& nums) {
        long long res = 0;
        for (int i = 0, j = nums.size() - 1; i <= j; ++i, --j) {
            if (i < j) {
                res += stoll(to_string(nums[i]) + to_string(nums[j]));
            }
            else {
                res += nums[i];
            }
        }
        return res;
    }
};

void testFindTheArrayConcVal() {
    Solution solution;
    vector<int> nums1 {7, 52, 2, 4};
    cout << solution.findTheArrayConcVal(nums1) << endl;
    vector<int> nums2 {5, 14, 13, 8, 12};
    cout << solution.findTheArrayConcVal(nums2) << endl;
}

int main() {
    testFindTheArrayConcVal();
    return 0;
}