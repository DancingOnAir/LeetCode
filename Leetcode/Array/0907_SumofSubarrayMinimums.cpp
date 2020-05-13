#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0, n = A.size(), j = 0, k = 0, mod = 1e9 + 7;
        stack<int> stk;

        for (int i = 0; i <= n; ++i) {
            while (!stk.empty() && A[stk.top()] > (i == n ? 0 : A[i])) {
                j = stk.top();
                stk.pop();

                k = stk.empty() ? -1 : stk.top();

                res = (res + A[j] * (i - j) * (j - k)) % mod;
            }

            stk.emplace(i);
        }

        return res;
    }

    // monotonous increase stack
    int sumSubarrayMins1(vector<int>& A) {
        if (A.empty())
            return 0;

        int n = A.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> prevStk, nextStk;

        for (int i = 0; i < n; ++i) {
            left[i] = i + 1;
            right[i] = n - i;
        }

        for (int i = 0; i < n; ++i) {
            // for previous less
            while (!prevStk.empty() && prevStk.top().first > A[i]) {
                prevStk.pop();
            }
            left[i] = prevStk.empty() ? i + 1 : i - prevStk.top().second;
            prevStk.emplace(make_pair(A[i], i));

            while (!nextStk.empty() && nextStk.top().first > A[i]) {
                auto x = nextStk.top();
                nextStk.pop();
                right[x.second] = i - x.second;
            }
            nextStk.emplace(make_pair(A[i], i));
        }

        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            res = (res + A[i] * left[i] * right[i]) % mod;
        }

        return res;
    }

    // brute force
    int sumSubarrayMins2(vector<int>& A) {
        if (A.empty())
            return 0;

        int mod = 1e9 + 7;
        int n = A.size();
        long long res = 0;
        int minValue = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    res += A[i];
                    minValue = A[i];
                    continue;
                }

                minValue = min(minValue, A[j]);
                res += minValue;
            }
        }

        return (int)(res % mod);
    }
};

void testSumSubarrayMins() {
    Solution solution;

    vector<int> A1 {3, 1, 2, 4};
    cout << solution.sumSubarrayMins(A1) << endl;

    vector<int> A2 {71, 55, 82, 55};
    cout << solution.sumSubarrayMins(A2) << endl;
}

int main() {
    testSumSubarrayMins();

    return 0;
}