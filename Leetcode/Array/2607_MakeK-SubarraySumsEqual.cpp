#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
class Solution {
public:
    // https://leetcode.cn/problems/make-k-subarray-sums-equal/solution/zhuan-huan-zhong-wei-shu-tan-xin-pei-shu-4dut/
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        k = gcd(k, n);
        vector<vector<int>> g(k);
        for (int i = 0; i < n; ++i) {
            g[i % k].push_back(arr[i]);
        }

        long long res = 0;
        for (auto& b : g) {
            sort(b.begin(), b.end());
            for (int x : b) {
                res += abs(b[b.size() / 2] - x);
            }
        }
        return res;
    }
};

void testMakeSubKSumEqual() {
    Solution solution;
    vector<int> arr1 {1, 4, 1, 3};
    cout << solution.makeSubKSumEqual(arr1, 2) << endl;
    vector<int> arr2 {2, 5, 5, 7};
    cout << solution.makeSubKSumEqual(arr2, 3) << endl;
    vector<int> arr3 {2, 10, 9};
    cout << solution.makeSubKSumEqual(arr3, 1) << endl;
}

int main() {
    testMakeSubKSumEqual();
    return 0;
}