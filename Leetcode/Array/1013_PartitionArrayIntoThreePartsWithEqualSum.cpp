#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        vector<int> presum {0};
        for (int a : A) {
            presum.emplace_back(presum.back() + a);
        }

        if (presum[n] % 3) {
            return false;
        }

        int avg = presum[n] / 3;
        for (int i = 1; i < n - 1; ++i) {
            if (presum[i] == avg) {
                for (int j = i + 1; j < n; ++j) {
                    if (presum[j] - presum[i] == avg && presum[n] - presum[j] == avg) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

void testCanThreePartsEqualSum() {
    Solution solution;

    vector<int> A1 {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    cout << (solution.canThreePartsEqualSum(A1)? "True" : "False") << endl;

    vector<int> A2 {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    cout << (solution.canThreePartsEqualSum(A2)? "True" : "False") << endl;

    vector<int> A3 {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    cout << (solution.canThreePartsEqualSum(A3)? "True" : "False") << endl;
}

int main() {
    testCanThreePartsEqualSum();

    return 0;
}