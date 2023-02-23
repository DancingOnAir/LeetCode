#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // presum + binary search
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> presum = {0};
        for (int x : nums) {
            presum.push_back(presum.back() + x);
        }

        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            int l = i, r = n;
            long long cur = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                long long total = (presum[mid] - presum[i - 1]) * (mid - i + 1);
                if (total >= k) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                    cur = mid;
                }
            }

            if (cur != -1) {
                res += cur - i + 1;
            }
        }

        return res;
    }
};

void testCountSubarrays() {
    Solution solution;
    vector<int> nums1{2,1,4,3,5};
    cout << solution.countSubarrays(nums1, 10) << endl;
    vector<int> nums2{1,1,1};
    cout << solution.countSubarrays(nums2, 5) << endl;
}

int main() {
    testCountSubarrays();
    return 0;
}