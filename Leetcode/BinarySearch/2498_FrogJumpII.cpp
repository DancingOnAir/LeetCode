#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool possible(int k, vector<int>& stones) {
        unordered_set<int> seen;
        int cur = 0, pre = 0;
        while (cur < stones.size()) {
            if (stones[cur] - stones[pre] > k) {
                if (cur == pre + 1) {
                    return false;
                }
                pre = cur - 1;
                seen.emplace(pre);
            }

            ++cur;
        }

        cur = stones.size() - 1;
        pre = stones.size() - 1;
        while (cur >= 0) {
            if (seen.count(cur)) {
                --cur;
                continue;
            }

            if (stones[pre] - stones[cur] <= k) {
                pre = cur;
            }
            else {
                return false;
            }

            --cur;
        }

        return true;
    }

    // binary search
    int maxJump(vector<int>& stones) {
        int left = 1, right = 1e9;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid, stones)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

    // greedy
    int maxJump1(vector<int>& stones) {
        int res = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); ++i) {
            res = max(res, stones[i] - stones[i - 2]);
        }
        return res;
    }
};

void testMaxJump() {
    Solution solution;

    vector<int> stones1 {0,2,5,6,7};
    cout << solution.maxJump(stones1) << endl;
    vector<int> stones2 {0,3,9};
    cout << solution.maxJump(stones2) << endl;
}

int main() {
    testMaxJump();
    return 0;
}