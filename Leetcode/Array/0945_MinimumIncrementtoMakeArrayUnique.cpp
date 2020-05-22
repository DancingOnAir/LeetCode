#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    int minIncrementForUnique2(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return 0;

        unordered_map<int, int> m;
        int res = 0;
        for (int a : A) {
            int temp = 0;
            while (m.count(a + temp)) {
                ++temp;
            }

            for (int i = a; i <= a + temp; ++i)
                m[i] = a + temp;

            res += m[a] - a;
        }

        return res;
    }

    int minIncrementForUnique(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return 0;

        map<int, int> m;
        for (int a : A)
            ++m[a];
        
        int res = 0, need = 0;
        for (auto& x : m) {
            res += x.second * max(need - x.first, 0) + x.second * (x.second - 1) / 2;
            need = max(need, x.first) + x.second;
        }

        return res;
    }

    int minIncrementForUnique1(vector<int>& A) {
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