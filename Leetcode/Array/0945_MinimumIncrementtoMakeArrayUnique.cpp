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
        
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int val = 0;
            while (m.count(A[i])) {
                ++val;
                ++A[i];
            }

            m[A[i]] = 1;
            res += val;
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