#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/solutions/3312018/index-array/?orderBy=most_votes
    long long findScore(vector<int>& nums) {
        long long res = 0, n = nums.size();
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

        vector<int> seen(n);
        for (int i = 0; i < n; ++i) {
            if (!seen[arr[i][1]]) {
                res += arr[i][0];
                seen[arr[i][1]] = seen[max(0, arr[i][1] - 1)] = seen[min((int)n - 1, arr[i][1] + 1)] = 1;
            }
        }
        return res;
    }
};

void testFindScore() {
    Solution solution;
    vector<int> nums1 {2,1,3,4,5,2};
    cout << solution.findScore(nums1) << endl;
    vector<int> nums2 {2,3,5,1,3,2};
    cout << solution.findScore(nums2) << endl;
}

int main() {
    testFindScore();
    return 0;
}
