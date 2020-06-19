#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        auto n = A.size();
        if (n < 2)
            return A;
        
        int left = n - 2;
        while (left >= 0 && A[left] <= A[left + 1]) {
            --left;
        }

        if (left < 0)
            return A;

        int right = n - 1;
        while (A[right] >= A[left]) {
            --right;
        }

        while (A[right] == A[right - 1]) {
            --right;
        }

        swap(A[left], A[right]);
        return A;
    }
};

void printRes(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testPrevPermOpt1() {
    Solution solution;

    vector<int> A1 {3, 2, 1};
    auto res1 = solution.prevPermOpt1(A1);
    printRes(res1);

    vector<int> A2 {1, 1, 5};
    auto res2 = solution.prevPermOpt1(A2);
    printRes(res2);

    vector<int> A3 {1, 9, 4, 6, 7};
    auto res3 = solution.prevPermOpt1(A3);
    printRes(res3);

    vector<int> A4 {3, 1, 1, 3};
    auto res4 = solution.prevPermOpt1(A4);
    printRes(res4);
}

int main() {
    testPrevPermOpt1();

    return 0;
}