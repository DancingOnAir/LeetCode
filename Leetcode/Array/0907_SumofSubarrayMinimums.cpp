#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
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
}

int main() {
    testSumSubarrayMins();

    return 0;
}