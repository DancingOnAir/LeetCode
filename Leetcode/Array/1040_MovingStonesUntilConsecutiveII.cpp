#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());

        int mx = stones[n - 1] - stones[0] + 1 - n;
        mx -= min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1);

        int mi = mx;
        int left = 0, right = 0;
        for (; left < n; ++left) {
            while (right + 1 < n && stones[right + 1] - stones[left] + 1 <= n) {
                ++right;
            }

            int cost = n - (right - left + 1);
            if (right - left + 1 == n - 1 && stones[right] - stones[left] + 1 == n - 1) {
                cost = 2;
            }

            mi = min(mi, cost);
        }

        return {mi, mx};
    }
};

void printRes(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testNumMovesStonesII() {
    Solution solution;

    vector<int> stones1 {7, 4, 9};
    auto res1 = solution.numMovesStonesII(stones1);
    printRes(res1);

    vector<int> stones2 {6, 5, 4, 3, 10};
    auto res2 = solution.numMovesStonesII(stones2);
    printRes(res2);

    vector<int> stones3 {100, 101, 104, 102, 103};
    auto res3 = solution.numMovesStonesII(stones3);
    printRes(res3);
}

int main() {
    return 0;
}