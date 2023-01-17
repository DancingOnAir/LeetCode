#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<long long> cnt(30);
        // unordered_map<int, int> m;
        for (int x : unordered_set<int>(nums.begin(), nums.end())) {
            ++cnt[__builtin_popcount(x)];
        }

        long long res = 0;
        for (int i = 1; i < 30; ++i) {
            for (int j = 1; j < 30; ++j) {
                if (i + j >= k) {
                    res += cnt[i] * cnt[j];
                }
            }
        }

        return res;
    }
};

void testCountExcellentPairs() {
    Solution solution;
    vector<int> nums1{1, 2, 3, 1};
    cout << solution.countExcellentPairs(nums1, 3) << endl;
    vector<int> nums2{5, 1, 1};
    cout << solution.countExcellentPairs(nums2, 10) << endl;
}

int main() {
    testCountExcellentPairs();
    return 0;
}