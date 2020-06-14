#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {

        int n = A.size();
        int m = B.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0] = (A[i] == B[j]) ? 1 : 0;
                }
                else if (i == 0) {
                    dp[0][j] = (A[i] == B[j]) ? 1 : dp[0][j - 1];
                }
                else if (j == 0) {
                    dp[i][0] = (A[i] == B[j]) ? 1 : dp[i - 1][j];
                }
                else {
                    dp[i][j] = (A[i] == B[j]) ? (dp[i - 1][j - 1] + 1) : max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

void testMaxUncrossedLines() {
    Solution solution;

    vector<int> A1 {1, 4, 2};
    vector<int> B1 {1, 2, 4};
    cout << solution.maxUncrossedLines(A1, B1) << endl;

    vector<int> A2 {2, 5, 1, 2, 5};
    vector<int> B2 {10,5, 2, 1, 5, 2};
    cout << solution.maxUncrossedLines(A2, B2) << endl;

    vector<int> A3 {1, 3, 7, 1, 7, 5};
    vector<int> B3 {1, 9, 2, 5, 1};
    cout << solution.maxUncrossedLines(A3, B3) << endl;
}

int main() {
    testMaxUncrossedLines();

    return 0;
}