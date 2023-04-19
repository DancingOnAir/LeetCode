#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> dp;
        // 全部不选为0有1种取法
        dp[0] = 1;
        long long res = 0, pre = 0;
        for (int x : nums) {
            pre ^= x;
            res += dp[pre];
            dp[pre] += 1;
        }

        return res;
    }
};

void testBeautifulSubarrays() {
    Solution solution;
    vector<int> nums1 {4, 3, 1, 2, 4};
    cout << solution.beautifulSubarrays(nums1) << endl;
    vector<int> nums2 {1, 10, 4};
    cout << solution.beautifulSubarrays(nums2) << endl;
}

int main() {
    testBeautifulSubarrays();
    return 0;
}
