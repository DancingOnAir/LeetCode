#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return 0;

        // int minVal = *min_element(A.begin(), A.end());
        // int maxVal = *max_element(A.begin(), A.end());

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 2; j <= n && i + j <= n; ++j) {
                int minVal = *min_element(A.begin() + i, A.begin() + i + j);
                int maxVal = *max_element(A.begin() + i, A.begin() + i + j);

                res += maxVal - minVal;
            }
        }
        // res = maxVal - minVal;
        // for (int i = 0; i < A.size(); ++i) {
        //     for (int j = n - 1; j > 1; --j) {
        //         while (i + j <= n) {

        //         }
        //     }
        // }

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
