#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        vector<int> presum(1);

        for (int a : A) {
            presum.emplace_back(presum.back() + a);
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if ((presum[j] - presum[i]) % K == 0) {
                    ++res;
                }
            }
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