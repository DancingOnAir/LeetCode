#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return 0;

        sort(A.begin(), A.end());
        int res = 0;

        for (int i = 1; i < n; ++i) {
            if (A[i] <= A[i - 1]) {
                int pre = A[i];
                A[i] = A[i - 1] + 1;
                res += A[i] - pre;
            }
        }

        return res;
    }
};

void testMinIncrementForUnique() {
    Solution solution;

    vector<int> A1 {1, 2, 2};
    cout << solution.minIncrementForUnique(A1) << endl;

    vector<int> A2 {3, 2, 1, 2, 1, 7};
    cout << solution.minIncrementForUnique(A2) << endl;
}

int main() {
    testMinIncrementForUnique();

    return 0;
}