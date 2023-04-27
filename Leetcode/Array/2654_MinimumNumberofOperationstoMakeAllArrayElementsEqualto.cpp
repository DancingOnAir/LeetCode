#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) {
            return nums.size() - ones;
        }

        int res = 0x3f3f3f;
        for(int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                x = gcd(x, nums[j]);
                if (x == 1) {
                    res = min(res, j - i);
                }
            }
        }
        
        if (res == 0x3f3f3f) {
            return -1;
        }
        return nums.size() - 1 + res;
    }
};

void testMinOperations() {
    Solution solution;
    vector<int> nums1 {2,6,3,4};
    cout << solution.minOperations(nums1) << endl;
    vector<int> nums2 {2,10,6,14};
    cout << solution.minOperations(nums2) << endl;
    
}

int main() {
    testMinOperations();
    return 0;
}