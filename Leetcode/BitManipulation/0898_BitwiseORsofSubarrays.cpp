#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs1(vector<int>& A) {
        unordered_set<int> res;
        vector<int> memo(A.size());
        int pre = -1;

        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == pre) {
                memo[i] = A[i];
                continue;
            }

            pre = A[i];
            if (A[i] == 0) {
                res.emplace(0);
            } else {
                for (int j = i; j >= 0; --j) {
                    int v = A[i] | memo[j];
                    if (v == memo[j])
                        break;
                    else
                    {
                        memo[j] = v;
                        res.emplace(v);
                    }
                }
            }
        }

        return res.size();
    }

    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return n;

        unordered_set<int> res;
        for (int i = 0; i < n; ++i) {
            res.emplace(A[i]);

            for (int j = i - 1; j >= 0; --j) {
                int temp = (A[i] | A[j]);
                if (A[j] == temp)
                    break;

                A[j] |= A[i];
                res.emplace(A[j]);
            }
        }

        return res.size();
    }
};

void testSubarrayBitwiseORs() {
    Solution solution;

    vector<int> A1 { 0 };
    cout << solution.subarrayBitwiseORs(A1) << endl;

    vector<int> A2 { 1, 1, 2 };
    cout << solution.subarrayBitwiseORs(A2) << endl;

    vector<int> A3 { 1, 2, 4 };
    cout << solution.subarrayBitwiseORs(A3) << endl;

    vector<int> A4 { 3, 11 };
    cout << solution.subarrayBitwiseORs(A4) << endl;
}

int main() {
    testSubarrayBitwiseORs();

    return 0;
}