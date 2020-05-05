#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = 0;
        for (int a : A) {
            sum1 += a;
        }

        int sum2 = 0;
        unordered_set<int> s;
        for (int b : B) {
            sum2 += b;
            s.emplace(b);
        }

        int diff = (sum1 - sum2) / 2;

        vector<int> res;
        for (int i = 0; i < A.size(); ++i) {
            if (s.count(A[i] - diff)) {
                res.emplace_back(A[i]);
                res.emplace_back(A[i] - diff);

                return res;
            }
        }
        return res;
    }
};

void printNums(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testFairCandySwap() {
    Solution solution;

    vector<int> A1 {1, 1}, B1 {2, 2};
    auto res1 = solution.fairCandySwap(A1, B1);
    printNums(res1);

    vector<int> A2 {1, 2}, B2 {2, 3};
    auto res2 = solution.fairCandySwap(A2, B2);
    printNums(res2);

    vector<int> A3 {2}, B3 {1, 3};
    auto res3 = solution.fairCandySwap(A3, B3);
    printNums(res3);

    vector<int> A4 {1, 2, 5}, B4 {2, 4};
    auto res4 = solution.fairCandySwap(A4, B4);
    printNums(res4);
}

int main() {
    testFairCandySwap();
    return 0;
}