#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {

        for (int i = 1; i < A.size(); ++i) {
            A[i] += A[i - 1];
        }

        int maxL = A[L - 1], maxM = A[M - 1], res = A[L + M - 1];

        for (int i = L + M; i < A.size(); ++i) {
            maxL = max(maxL, A[i - M] - A[i - L - M]);
            maxM = max(maxM, A[i - L] - A[i - L - M]);

            res = max(res, max(maxL + A[i] - A[i - M], maxM + A[i] - A[i - L]));
        }

        return res;
    }

    int maxSumTwoNoOverlap1(vector<int>& A, int L, int M) {
        auto n = A.size();

        vector<int> presum{0};
        for (auto a : A) {
            presum.emplace_back(presum.back() + a);
        }
        
        int res = INT_MIN;
        for (int i = L; i <= n; ++i) {
            int tempMaxM = INT_MIN;
            for (int j = M; j <= i - L; ++j) {
                tempMaxM = max(tempMaxM, presum[j] - presum[j - M]);
            }

            for (int j = i + M; j <=n; ++j) {
                tempMaxM = max(tempMaxM, presum[j] - presum[j - M]);
            }

            res = max(res, presum[i] - presum[i - L] + tempMaxM);
        }

        return res;
    }
};

void testMaxSumTwoNoOverlap() {
    Solution solution;

    vector<int> A1 {0,6,5,2,2,5,1,9,4};
    int L1 = 1, M1 = 2;
    cout << solution.maxSumTwoNoOverlap(A1, L1, M1) << endl;

    vector<int> A2 {3,8,1,3,2,1,8,9,0};
    int L2 = 3, M2 = 2;
    cout << solution.maxSumTwoNoOverlap(A2, L2, M2) << endl;

    vector<int> A3 {2,1,5,6,0,9,5,0,3,8};
    int L3 = 4, M3 = 3;
    cout << solution.maxSumTwoNoOverlap(A3, L3, M3) << endl;
}

int main() {
    testMaxSumTwoNoOverlap();

    return 0;
}