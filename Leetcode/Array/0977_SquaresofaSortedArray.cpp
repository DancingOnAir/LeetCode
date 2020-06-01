#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int n = A.size();
        int left = 0, right = n - 1, idx = n - 1;
        vector<int> res(n);

        while (left <= right) {
            int leftSquare = A[left] * A[left];
            int rightSquare = A[right] * A[right];

            if (leftSquare > rightSquare) {
                res[idx--] = leftSquare;
                ++left;
            }
            else {
                res[idx--] = rightSquare;
                right--;
            }
        }

        return res;
    }

    vector<int> sortedSquares1(vector<int>& A) {
        if (A[0] < 0) {
            sort(A.begin(), A.end(), [](int a, int b) { return abs(a) < abs(b); });
        }

        vector<int> res;
        for (int a : A) {
            res.emplace_back(a * a);
        }

        return res;
    }
};

void printRes(const vector<int>& nums) {
    for (int x : nums)
        cout << x << ", ";
    cout << endl;
}

void testSortedSquares() {
    Solution solution;

    vector<int> A1 { -4, -1, 0, 3, 10 };
    auto res1 = solution.sortedSquares(A1);
    printRes(res1);

    vector<int> A2 { -7, -3, 2, 3, 11 };
    auto res2 = solution.sortedSquares(A2);
    printRes(res2);
}

int main() {
    testSortedSquares();

    return 0;
}