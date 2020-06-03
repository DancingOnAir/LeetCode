#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if (!K)
            return A;

        vector<int> res;
        int extra = 0;
        while (K || !A.empty() || extra) {
            
            int val = extra;
            if (!A.empty()) {
                val += A.back();
                A.pop_back();
            }

            if (K) {
                val += K % 10;
                K /= 10;
            }

            extra = val / 10;
            res.emplace_back(val % 10);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

void printRes(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << ", ";
    }

    cout << endl;
}

void testAddToArrayForm() {
    Solution solution;

    vector<int> A1 = {1,2,0,0};
    int K1 = 34;
    auto res1 = solution.addToArrayForm(A1, K1);
    printRes(res1);

    vector<int> A2 = {2, 7, 4};
    int K2 = 181;
    auto res2 = solution.addToArrayForm(A2, K2);
    printRes(res2);

    vector<int> A3 = {2, 1, 5};
    int K3 = 806;
    auto res3 = solution.addToArrayForm(A3, K3);
    printRes(res3);

    vector<int> A4 = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    int K4 = 1;
    auto res4 = solution.addToArrayForm(A4, K4);
    printRes(res4);
}

int main() {
    testAddToArrayForm();

    return 0;
}