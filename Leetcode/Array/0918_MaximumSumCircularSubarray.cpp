#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> presum(2 * n + 1);
        for (int i = 0; i < 2 * n; ++i) {
            presum[i + 1] = presum[i] + A[i % n];
        }

        int res = A[0];
        deque<int> dq;
        dq.emplace_back(0);

        for (int i = 1; i <= 2 * n; ++i) {
            // right - left <= n -> left >= right -n
            if (i - n > dq.front())
                dq.pop_front();

            res = max(res, presum[i] - presum[dq.front()]);
            while (!dq.empty() && presum[i] <= presum[dq.back()]) {
                dq.pop_back();
            }

            dq.emplace_back(i);
        }

        return res;
    }

    int maxSubarraySumCircular1(vector<int>& A) {
        int sum = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int i : A) {
            curMax = i + max(curMax, 0);
            maxSum = max(maxSum, curMax);

            curMin = i + min(curMin, 0);
            minSum = min(minSum, curMin);

            sum += i;
        }

        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }

    // presum solution, but TLE
    int maxSubarraySumCircular2(vector<int>& A) {
        int n = A.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return A[0];

        int res = INT_MIN;
        int sum = 0;

        A.insert(A.end(), A.begin(), prev(A.end()));
        vector<int> presum;
        for (int i = 0; i < 2*n - 1; ++i) {
            sum += A[i];
            presum.emplace_back(sum);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0)
                    res = max(res, presum[i + j]);
                else
                    res = max(res, presum[i + j] - presum[i - 1]);
            }
        }

        return res;
    }
};

void testMaxSubarraySumCircular() {
    Solution solution;

    vector<int> A1 {1, -2, 3, -2};
    cout << solution.maxSubarraySumCircular(A1) << endl;

    vector<int> A2 {5, -3, 5};
    cout << solution.maxSubarraySumCircular(A2) << endl;

    vector<int> A3 {3, -1, 2, -1};
    cout << solution.maxSubarraySumCircular(A3) << endl;

    vector<int> A4 {3,-2,2,-3};
    cout << solution.maxSubarraySumCircular(A4) << endl;

    vector<int> A5 {-2,-3,-1};
    cout << solution.maxSubarraySumCircular(A5) << endl;

    vector<int> A6 {3, 1, 3, 2, 6};
    cout << solution.maxSubarraySumCircular(A6) << endl;
}

int main() {
    testMaxSubarraySumCircular();

    return 0;
}