#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> m;
        int n = A.size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            m[A[i]] = i;
            for (int j = 0; j < i; ++j) {
                int k = m.find(A[i] - A[j]) == m.end() ? -1 : m[A[i] - A[j]];
                dp[j][i] = (A[i] - A[j] < A[j] && k >= 0) ? dp[k][j] + 1 : 2;
                res = max(res, dp[j][i]);
            }
        }

        return res > 2 ? res : 0;
    }

    int lenLongestFibSubseq1(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());

        int res = 2;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                long long a = A[i];
                long long b = A[j];
                // multiplication maybe overflow, use long long type
                if (b * (res - 2) >= A.back())
                    break;

                int l = 2;

                while (s.count(a + b)) {
                    b = a + b;
                    a = b - a;
                    ++l;
                }

                res = max(res, l);
            }
        }

        return res > 2 ? res : 0;
    }

    int lenLongestFibSubseq2(vector<int>& A) {
        int n = A.size();

        if (n < 3)
            return 0;

        vector<int> dp(n);
        unordered_set<int> s;
        vector<vector<int>> fibonaccis;

        s.emplace(A[0]);
        s.emplace(A[1]);

        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] > A[i] / 2)
                    break;

                int diff = A[i] - A[j];
                if (diff != A[j] && s.count(diff)) {
                    bool isNew = true;

                    for (int k = 0; k < fibonaccis.size(); ++k) {
                        int len = fibonaccis[k].size();
                        if (fibonaccis[k][len - 2] + fibonaccis[k][len - 1] == A[i]) {
                            fibonaccis[k].emplace_back(A[i]);

                            if (fibonaccis[k][len - 2] == A[j])
                                isNew = false;
                        }
                    }

                    if (isNew) {
                        fibonaccis.push_back({A[j], A[i] - A[j], A[i]});
                    }
                }
            }

            s.emplace(A[i]);
        }

        int res = 0;
        for (int i = 0; i < fibonaccis.size(); ++i) {
            res = max(res, (int)fibonaccis[i].size());
        }

        return res;
    }
};

void testLenLongestFibSubseq() {
    Solution solution;
    
    vector<int> nums1 {1, 2, 3, 4, 5, 6, 7, 8};
    cout << solution.lenLongestFibSubseq(nums1) << endl;

    vector<int> nums2 {1, 3, 7, 11, 12, 14, 18};
    cout << solution.lenLongestFibSubseq(nums2) << endl;

    // 4, 14, 18, 32, 50
    vector<int> nums3 {2, 4, 7, 8, 9, 10, 14, 15, 18, 23, 32, 50};
    cout << solution.lenLongestFibSubseq(nums3) << endl;
}

int main() {
    testLenLongestFibSubseq();

    return 0;
}