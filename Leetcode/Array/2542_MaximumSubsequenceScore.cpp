#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums1.size(); ++i) {
            v.push_back(make_pair(nums2[i], nums1[i]));
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        priority_queue<int> pq;
        long long res = 0, total = 0;
        for (auto& p : v) {
            total += p.second;
            pq.push(-p.second);

            if (pq.size() > k) {
                total += pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                res = max(res, total * p.first);
            }
        }
        return res;
    }
};

void testMaxScore() {
    Solution solution;
    vector<int> nums1 {1, 3, 3, 2};
    vector<int> nums2 {2, 1, 3, 4};
    cout << solution.maxScore(nums1, nums2, 3) << endl;
}

int main() {
    testMaxScore();
    return 0;
}
