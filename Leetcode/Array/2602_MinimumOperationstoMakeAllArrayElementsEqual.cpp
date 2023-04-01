#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> preSum{0};
        for (int x : nums) {
            preSum.push_back(preSum.back() + x);
        }

        vector<long long> res;
        for (long long q : queries) {
            int i = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            res.push_back(q * i - preSum[i] + preSum.back() - preSum[i] - (nums.size() - i) * q);
        }

        return res;
    }
};

void print(vector<long long>& nums) {
    if (nums.empty())
        return;
    for (int x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}

void testMinOperations() {
    Solution solution;
    vector<int> nums1 {3, 1, 6, 8};
    vector<int> queries1 {1, 5};
    auto res1 = solution.minOperations(nums1, queries1);
    print(res1);

    vector<int> nums2 {2, 9, 6, 3};
    vector<int> queries2 {10};
    auto res2 = solution.minOperations(nums2, queries2);
    print(res2);
}

int main() {
    testMinOperations();
    return 0;
}