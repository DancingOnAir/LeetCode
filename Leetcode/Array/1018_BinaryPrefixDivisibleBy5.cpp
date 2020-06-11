#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int val = 0;
        for (auto i = 0; i < A.size(); ++i) {
            val <<= 1;
            val += A[i];
            val %= 10;
            
            if (val == 0 || val == 5) {
                res.emplace_back(true);
            }
            else {
                res.emplace_back(false);
            }
        }

        return res;
    }
};

void printRes(const vector<bool>& res) {
    for (auto r : res) {
        if (r) {
            cout << "true";
        }
        else {
            cout << "false";
        }

        cout << ", ";
    }

    cout << endl;
}

void testPrefixesDivBy5() {
    Solution solution;

    vector<int> A1 {0, 1, 1};
    auto res1 = solution.prefixesDivBy5(A1);
    printRes(res1);

    vector<int> A2 {1, 1, 1};
    auto res2 = solution.prefixesDivBy5(A2);
    printRes(res2);

    vector<int> A3 {0, 1, 1, 1, 1, 1};
    auto res3 = solution.prefixesDivBy5(A3);
    printRes(res3);

    vector<int> A4 {1, 1, 1, 0, 1};
    auto res4 = solution.prefixesDivBy5(A4);
    printRes(res4);
}

int main() {
    testPrefixesDivBy5();

    return 0;
}