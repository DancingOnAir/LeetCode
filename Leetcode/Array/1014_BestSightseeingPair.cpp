#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        auto n = A.size();

        int maxVal = max(A[0], A[1] + 1);
        int res = A[0] + A[1] - 1;
        for (auto i = 2; i < n; ++i) {
            res = max(res, maxVal + A[i] - i);
            maxVal = max(maxVal, A[i] + i);
        }

        return res;
    }
};

void testMaxScoreSightseeingPair() {
    Solution solution;
    vector<int> A1 {8, 1, 5, 2, 6};
    cout << solution.maxScoreSightseeingPair(A1) << endl;
}

int main() {
    testMaxScoreSightseeingPair();

    return 0;
}