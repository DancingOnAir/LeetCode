#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>

using namespace std;
class Solution {
public:
    // https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-48c1d/wo-xie-le--9c7a4/
    // 寻找右边边界，找到刚好超出maxSum的数，再减1得到值
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> ps(100001);
        for (int x : banned) {
            ps[x] = x;
        }
        partial_sum(ps.begin(), ps.end(), ps.begin());

        int left = 1, right = n;
        int cnt = 0;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int cur  = (1 + mid) * mid / 2 - ps[mid];
            if (cur > maxSum) {
                right = mid - 1;
            }
            else if (cur < maxSum) {
                left = mid + 1;
            }
            else if (cur == maxSum) {
                left = mid + 1;
            }
        }

        --left;
        for (int i = 0; i < left; ++i) {
            cnt += ps[i] != ps[i + 1];
        }

        return left - cnt;
    }

    // hash set
    int maxCount1(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int res = 0;
        for (int i = 1; i <= n && maxSum >= 0; ++i) {
            if (!st.count(i)) {
                maxSum -= i;
                res += maxSum >= 0;
            }
        }
        return res;
    }
};

void testMaxCount() {
    Solution solution;

    vector<int> banned1 {1, 6, 5};
    cout << solution.maxCount(banned1, 5, 6) << endl;

    vector<int> banned2 {1, 2, 3, 4, 5, 6, 7};
    cout << solution.maxCount(banned2, 8, 1) << endl;

    vector<int> banned3 {11};
    cout << solution.maxCount(banned3, 7, 50) << endl;
}

int main() {
    testMaxCount();
    return 0;
}
