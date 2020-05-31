#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0, presum = 0;
        vector<int> remainder(K);
        remainder[0] = 1;

        for (int a : A) {
            presum = (presum + a % K + K) % K;
            res += remainder[presum]++;
        }

        return res;
    }
};

void testSubarraysDivByK() {
    Solution solution;

    vector<int> A1 {4, 5, 0, -2, -3, 1};
    int K1 = 5;
    cout << solution.subarraysDivByK(A1, K1) << endl;
}

int main() {
    testSubarraysDivByK();

    return 0;
}