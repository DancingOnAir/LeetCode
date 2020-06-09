#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        for (int a : A) {
            sum += a;
        }

        if (sum % 3) {
            return false;
        }

        int val = 0;
        int times = 0;
        for (int i = 0; i < n; ++i) {
            val += A[i];
            if (val == sum / 3) {
                ++times;
                val = 0;
            }
        }

        return times >= 3;
    }

    bool canThreePartsEqualSum1(vector<int>& A) {
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