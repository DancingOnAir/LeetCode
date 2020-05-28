#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        stack<int> decrease;
        for (int i = 0; i < n; ++i) {
            if (decrease.empty() || A[decrease.top()] > A[i]) {
                decrease.emplace(i);
            }
        }

        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!decrease.empty() && A[decrease.top()] <= A[i]) {
                res = max(res, i - decrease.top());
                decrease.pop();
            }
        }

        return res;
    }
};

void testMaxWidthRamp() {
    Solution solution;

    vector<int> A1 {6, 0, 8, 2, 1, 5};
    cout << solution.maxWidthRamp(A1) << endl;

    vector<int> A2 {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << solution.maxWidthRamp(A2) << endl;
}

int main() {
    testMaxWidthRamp();
    return 0;
}