#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int mx = 1;
        for (int x: nums) {
            int bits = 0;
            while (x) {
                res += x & 1;
                ++bits;
                x >>= 1;
            }
            mx = max(mx, bits);
        }

        return res + mx - 1;
    }
};

void testMinOperations() {
    Solution solution;
    vector<int> nums {1, 5};
    cout << solution.minOperations(nums) << endl;

    nums = {2, 2};
    cout << solution.minOperations(nums) << endl;

    nums = {4, 2, 5};
    cout << solution.minOperations(nums) << endl;
}

int main() {
    testMinOperations();
    return 0;
}