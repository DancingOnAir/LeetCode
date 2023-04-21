#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;
class Solution {
public:
    int maxScore(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int res = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        while (total <= 0 && !pq.empty()) {
            total -= pq.top();
            pq.pop();
            --res;
        }
        return res;
    }
};

void testMaxScore() {
    Solution solution;
    vector<int> nums1 {2,-1,0,1,-3,3,-3};
    cout << solution.maxScore(nums1) << endl;
    vector<int> nums2 {-2,-3,0};
    cout << solution.maxScore(nums2) << endl;
}

int main() {
    testMaxScore();
    return 0;
}