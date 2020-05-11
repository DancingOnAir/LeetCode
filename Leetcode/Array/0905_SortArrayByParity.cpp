#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return A;

        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && (A[i] & 1) == 0)
                ++i;
            
            if (i >= n || i >= j)
                return A;

            while (j >= 0 && (A[j] & 1))
                --j;

            if (j < 0 || i >= j)
                return A;

            swap(A[i++], A[j--]);
        }

        return A;
    }
};

void printNums(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testSortArrayByParity() {
    Solution solution;

    // vector<int> A1 {3, 1, 2, 4};
    // auto res1 = solution.sortArrayByParity(A1);
    // printNums(res1);

    // vector<int> A2 {0, 2};
    // auto res2 = solution.sortArrayByParity(A2);
    // printNums(res2);

    vector<int> A3 {0, 1};
    auto res3 = solution.sortArrayByParity(A3);
    printNums(res3);
}

int main() {
    testSortArrayByParity();
    
    return 0;
}