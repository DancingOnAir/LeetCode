#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return 0;

        static const int mod = 1e9 + 7;
        
        vector<int> count(n);
        count[0] = 1;
        for (int i = 1; i < n; ++i) {
            count[i] = (count[i - 1] << 1) % mod;
        }

        sort(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += (long long)A[i] * (count[i] - count[n - i - 1]) % mod;
            res %= mod;
        }

        return res;
    }
};

void testSumSubseqWidths() {
    Solution solution;

    vector<int> A1 { 2, 1, 3 };
    cout << solution.sumSubseqWidths(A1) << endl;
}

int main() {
    testSumSubseqWidths();

    return 0;
}
