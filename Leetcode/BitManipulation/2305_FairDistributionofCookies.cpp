#include <vector>
#include <iostream>
#include <algorithm>

using std::vector, std::cout, std::endl, std::max, std::min, std::sort;
class Solution {
public:
    void solve(int start, vector<int>& v, vector<int>& cookies, int k, int& res) {
        if (start >= cookies.size()) {
            int cur = 0;
            for (int x: v) {
                cur = max(cur, x);
            }
            res = min(res, cur);
            return;
        }

        for (int i = 0; i < k; ++i) {
            if (i > 0 && v[i] == v[i - 1]) {
                continue;
            }
            
            v[i] += cookies[start];
            solve(start + 1, v, cookies, k, res);
            v[i] -= cookies[start];
        }
    }

    // backtracking
    int distributeCookies(vector<int>& cookies, int k) {
        int res = 0x3f3f3f;
        vector<int> v(k);
        sort(cookies.begin(), cookies.end(), [](int& a, int& b) { return a > b; } );
        solve(0, v, cookies, k, res);
        return res;
    }
};

void testDistributeCookies() {
    Solution solution;

    vector<int> cookies1 {8,15,10,20,8};
    cout << solution.distributeCookies(cookies1, 2) << endl;
    vector<int> cookies2 {6,1,3,2,2,4,1,2};
    cout << solution.distributeCookies(cookies2, 3) << endl;
}

int main() {
    testDistributeCookies();
    return 0;
}